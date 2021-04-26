// Code of ShenZhou
inherit ROOM;
inherit F_SAVE;


#include <ansi.h>

int do_lingwu();

void create()
{
        set("name", "�㳡");
        set("short", "�㳡");
        set("long", "������һ�������Ĺ㳡����ʯ�̳ɵĵذ屻ȫ���ʿ��ɨ�ĸɸ�\n�������㳡��������һ��ʯ��(bei )��������������ؿ���С�֡�ʯ\n���Ա�����һ��ľͷ�ˣ��������죬������棬���б���һ��������\n\n");

        set("item_desc", ([
                "bei" : "���Ͽ��Ŷ��Ʊ޷���Ҫ�塣\n\n",
        ]));

        set("objects", ([
        ]));

        set("exits", ([
                "left" 	   : "/d/zhongnan/taijie",
        ]));

	set("no_clean_up", 0);
	set("valid_startroom", 1);

        setup();     
 
}


void init()
{       
        add_action("do_lingwu", "lingwu");
        
}


int do_lingwu(){
	
	int skill, exp;
		
	object me=this_player();

	if (this_player()->is_busy()) return notify_fail("����æ���ء�\n");
	
	if (me->query_skill("duanyun-bian",1)<150)
		return notify_fail("����Ʊ޷���Ϊ�����������侫����\n");

	if (!present("fuchen", me) && me->query("id")!="wsky")
                        return notify_fail("��û��Я��������\n\n");
	
	if (me->query_skill("duanyun-bian",1)>500)
		return notify_fail("�㿴�˿����ϵ�С�֣�������Щ���Լ���˵̫ǳ�ˡ�\n");

	if (me->query("neili")<30)
		return notify_fail("���������㡣\n");

	if (me->query("jingli")<30)
		return notify_fail("�㾫�����㡣\n");

	exp=me->query("combat_exp");
	while(skill*skill*skill<exp*10) skill++;
	
	if (me->query_skill("duanyun-bian",1)>skill)
		return notify_fail("�㿴�˿����ϵ�С�֣������Լ����鲻�������Щ��\n");

	message_vision("\n$N�ֳַ���վ��ʯ��ǰ��Ŭ���Ķ��Ŷ��Ʊ޵ľ��塣\n",me);

	me->start_busy(3);
	me->add("jingli",20);
	me->add("neili",20);

	if (random(100)<10){

		message_vision("\n$N���˿����Ե�ľ�ˣ��ֳַ�������ζ����ƺ��Զ��Ʊ޷���������\n",me);		
		this_player()->improve_skill("duanyun-bian", this_player()->query_skill("whip",1)/10);	

	}

	return 1;
}