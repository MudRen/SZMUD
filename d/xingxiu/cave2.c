// Code of ShenZhou
// room: /d/xingxiu/cave.c
// Jay 3/18/96

inherit ROOM;


void create()
{
	object ob;
        set("short", "ɽ��");
        set("long", @LONG
���ɽ�������ֲ�����ָ��ֻ�г��ڴ�͸��һ˿���ߡ�
LONG
        );
        set("exits", ([
            "out" : __DIR__"cave",
]));
	set("cost", 1);
        setup();
	set("no_clean_up", 1);
        //replace_program(ROOM);
//        ob=new("/d/xingxiu/obj/muding");
        ob=new("/d/xingxiu/obj/muding1");
        if(ob)
        ob->move(__DIR__"cave2");
}
/*void init()
{
        object ob;

        if( objectp( ob = present("shenmu wangding 2", this_object()) ) )
        destruct(ob);
}
*/
