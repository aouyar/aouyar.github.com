<table>
<col width="0"/>
<col width="*"/>
<tbody>
{% for post in post_list limit: 5 %}
{% capture post_title %}
{% if post.prjname %}
{{ post.prjname }} -
{% endif %}
{{ post.title }}
{% endcapture %}
<tr>
    <td>
        <div class="postdate">{{ post.date | date_to_string }}</div>
    </td>
    <td>
       <div class="posttitle">
{% if post.nopage %}     
            {{ post_title }}
{% else %}
            <a href="{{ post.url }}">{{ post_title }}</a>
{% endif %}
        </div>
        <div>
        {{ post.excerpt | markdownify }}
        </div>
    </td>
</tr>
{% endfor %}
</tbody>
</table>