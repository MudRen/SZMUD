// Code of ShenZhou
// Jay 5/11/97

inherit ROOM;

void create()
{
        set("short", "ͨ�Ե�");
	set("long", @LONG
������һ�齸ʯ������ΤС�����ڴ˴�����������һ�����ߵô�æ��һ
Щ������Ʒ�����ڵ��ϣ�������ʷ�ļ�֤��
LONG
        );

        set("exits", ([ 
		"south" : __DIR__"diaoyu",
	]));

        set("objects", ([ 
	        "/d/quanzhou/obj/beauty-book" : 1,
	        "/d/quanzhou/obj/touzi" : 1,
		"/d/dali/obj/diaogan" : 1,
        ]));

	set("cost", 1);
	set("outdoors", "island");
        setup();
        replace_program(ROOM);

}
