#include <ansi.h>
inherit ROOM;
void create()
{
set("short",HIM"������Դ"NOR);  
    set("long",
"
�㲻֪����������"HIM"������Դ"NOR",��������ڤ����һ�����̸��˵�صĺ�ȥ����
"
);
        set("exits", ([
"out" : "/d/city/wumiao",
"thd" : "/d/taohua/hyjuchu",
"gyz" : "/d/taihu/shufang",

]));
set("objects", ([
"/d/taohua/obj/tiexiao" : 1,
"/d/taohua/obj/zhuxiao" : 1,
"/d/taohua/obj/bagua" : 1,
]));
                 setup(); 
}
