    <!-- Google Analytics -->
    {% if site.google_analytics %}
    <script type="text/javascript">
      var _gaq = _gaq || [];
      _gaq.push(['_setAccount', '{{ site.google_analytics }}']);
      _gaq.push(['_trackPageview']);

      (function() {
        var ga = document.createElement('script'); ga.type = 'text/javascript'; ga.async = true;
        ga.src = ('https:' == document.location.protocol ? 'https://ssl' : 'http://www') + '.google-analytics.com/ga.js';
        var s = document.getElementsByTagName('script')[0]; s.parentNode.insertBefore(ga, s);
      })();
    </script>
    {% endif %}
  
    <!-- full skip link functionality in webkit browsers -->
    <script src="{{ page.baseptr }}/yaml/core/js/yaml-focusfix.js"></script>
    
    <!-- jQuery & Plugins -->
    <script src="{{ page.baseptr }}/lib/jquery-1.7.1.min.js"></script>
    <script src="{{ page.baseptr }}/js/jquery.gridbuilder.js"></script>
    <script src="{{ page.baseptr }}/yaml/add-ons/accessible-tabs/jquery.tabs.js"></script>
    <script src="{{ page.baseptr }}/yaml/add-ons/syncheight/jquery.syncheight.js"></script>
    <script src="{{ page.baseptr }}/js/domscript.js"></script>