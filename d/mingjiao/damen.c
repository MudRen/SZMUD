// Code of ShenZhou
// /d/mingjiao/damen.c
// Zhangchi 3/00

#include <ansi.h>
inherit ROOM;
void create()
{
    set("short", HIR"����ɽ��"NOR);
    set("long",@LONG    
�˴�������ɽ�ţ�����������ƽ̹���������졣ɽ�������������ò�
����ɣ��Գ��������ƷǷ��������һ��͹��Ĵ�ɽ���Ͽ��������ɷ���
��������ɫ���֣������̡���
LONG
	);
		set("objects",([
		__DIR__"npc/mingjiao_shouwei" : 4,
]));


 	set("exits",([
		      "northup" : __DIR__"shanmentongdao",	

			"south" : __DIR__"shankou",	
		      	]));
	set("outdoors", "mingjiao");
	set("cost", 1);
	setup();

}
int valid_leave(object me, string dir)
{
	object ob;
//	mapping fam = this_player()->query("family");
        if (dir == "northup" 
			&& objectp(ob=present("mingjiao shouwei", environment(me)))
			&&living(ob))
//			if (fam["family_name"] != "����")
			if (this_player()->query("family/family_name") != "����")
                return notify_fail(
				"���������ȵ�������������ʥ�أ���λ" + 	RANK_D->query_respect(me)+"�����ҽ���ͽ����ֹ��!\n");
        return ::valid_leave(me, dir);
}

