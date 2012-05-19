$(document).ready(function() {

	var domscripts = {

		init: function init () {

			var self = this;

			self.installStickyMenu();
			self.installTabs();
		},

		installStickyMenu: function installStickyMenu () {

			var header      = $('body > header'),
				headings    = $('#main h2'),
				nav         = $('nav#level2'),
				stickyClass = 'fix';

			if (nav.find('.ym-hlist').length > 0 ) {

				// install smallscreen menu
				var menu =	'<li><label for="ym-smnav" style="padding: 0 0.5em; color: rgba(255,255,255,.8)">Navigation:</label> '+
							'<select id="ym-smnav" style="font-size: 16px;"><option value="0" selected="selected" disabled="disabled">Go to ...</option>';
				var items = nav.find('a');
				$.each(items, function(key){
					menu += '<option data-target="'+$(this).attr('href')+'">'+$(this).text()+'</option>';
				});
				menu += '</select></li>';

				var smnav = $(menu).appendTo(nav.find('ul')).hide();

				$(window).bind('resize',function(){
					var width = $(window).width();
					
					if (width > 740) {
						smnav.siblings().show();
						smnav.hide();
					} else {
						smnav.siblings().hide();
						smnav.show();
					}
				});
				
				$(smnav).bind('change', function(){
					var target = $(this).find('option:selected').data('target');
					nav.find('a[href='+target+']').trigger('click');
				});

				$(document).bind('scroll',function(){
					var hOffset = header.offset().top+header.height(),
						top     = $(document).scrollTop(),
						trigger = false;

					// make it sticky ...
					if (hOffset < top) {
						if (nav.data(stickyClass) !== true) {
							nav.addClass(stickyClass).data(stickyClass,true);
						}
					} else {
						if (nav.data(stickyClass) !== false) {
							nav.removeClass(stickyClass).data(stickyClass,false);
						}
					}

					var nOffset = nav.height();

					// adjust active menu-item from scroll-value
					$.each(headings, function(key){
						var id        = '#'+$(this).attr('id'),
							offset    = $(this).offset().top,
							pos       = offset - top,
							targetPos = 0;

						if (nav.hasClass(stickyClass) === true) {
							targetPos = 2*nav.height();
						}

						if (pos > targetPos) {
							nav.find('a[href="'+id+'"]').parent().prev().addClass('active').siblings().removeClass('active');
							return false;
						} else if (pos < targetPos && pos > targetPos - nOffset) {
							nav.find('a[href="'+id+'"]').parent().addClass('active').siblings().removeClass('active');
							return false;
						}
					});

				});

				// initial check for scroll-status ...
				$(document).trigger('scroll');
				$(window).trigger('resize');

				if ($('body').hasClass('doc') === true) {

					var stateObj = { page: "index" };

					// jump to a named anchor ...
					$('#level2 a').bind('click', function(event){
						event.preventDefault();

						var id      = $(this).attr('href'),
							pos     = $(id).offset().top,
							nHeight = nav.height() + 6; // 6px whitespace

						// set active menu-item ...
						$(this).parent()
							.addClass('active')
							.siblings()
							.removeClass('active');

						$(id).focus();

						// adjust scroll-value
						if (nav.hasClass(stickyClass) === true) {
							$(document).scrollTop(pos-nHeight);
						} else {
							$(document).scrollTop(pos-2*nHeight);
						}
						// update URL id fragment
						history.pushState(stateObj, "docs", window.location.pathname + id);
					});
				}
			}
		},

		installTabs: function installTabs () {

			// standard behavoir in YAML docs
			$('.jquery_tabs:not([data-sync])').accessibleTabs({
				fx:"show",
				fxspeed: '',
				syncheights: false,
				tabhead: 'h5',
				tabbody:'.tab-content'
			});

			// "accessible tabs" sync example
			$('.jquery_tabs[data-sync="true"]').accessibleTabs({
				fx:"show",
				fxspeed: '',
				syncheights: true,
				tabhead: 'h5',
				tabbody:'.tab-content'
			});
		},

	};

	domscripts.init();
});

//check for deep links
$(window).load(function() {
	var fragment = location.href.split('#'),
		nav      = $('nav#level2');
			
	if (fragment.length > 0) {
		$(nav.find('a[href="#'+fragment[1]+'"]')).trigger('click');
	}
});
