// Room: /d/taishan/.c
// Updated by Piao 2001/10/16
#include <ansi.h>
inherit ROOM;
int bow_statue(object me);
void create()
{
	set("short", "����̨");
	set("long", @LONG
�����������ѡ��������������֮������·Ӣ�����ܼ�ѹȺ�ۣ�
�������������ʶ�������������Ϊͳ����ԭ���ֵ����䡣��̨��
�ڷ��ź����������������ڴ��������¡�̨�ϸ߸�����һ���죬
���飺�����е� �ĸ����֡� �������Ҹ���������λ������ʿ����
�߶�����һ���Ż�Ƥ���Σ�ʱ��������ǰ������ǰ���μ���������
��������������һ��ǰ��Ӣ�۵ĵ���(statue)��
LONG
	);

	set("exits", ([
		"down" : __DIR__"yuhuang",
		"southwest" : __DIR__"fengchansw",
		"southeast" : __DIR__"fengchanse",
		"northwest" : __DIR__"fengchannw",
		"northeast" : __DIR__"fengchanne",
	]));

	set("objects",([
		"/clone/npc/meng-zhu" : 1,
		__DIR__"npc/wei-shi1" : 4,
	]));

        set("no_clean_up", 1);
	set("outdoors", "taishan");
        set("item_desc", ([
              "statue" : "һ������ĵ�����������ų����Ϲ�(bow)��\n",
             
 ]));
	set("cost", 2);
	setup();
}

void init()
{       
	object ob;	
	add_action("do_bow","bow");
	if( objectp( ob = present("mengzhu 2", this_object()) ) )
	destruct(ob);
}

//add_action("do_bow", "bow");
int do_bow(string arg)
{
	object room;
	object me = this_player();
	if ((int)me->query("combat_exp")<100000) return notify_fail(CYN"���ϵ��������˸�����\n"NOR);
        if (!arg||arg!="statue") return notify_fail(CYN"���ϵ��������˸�����\n"NOR);
   
        message_vision(CYN"$N�����������������˸�����\n\n"
                   "ͻȻ�и���������ס$N������Աߵ�����ɽ����ȥ��\n\n"NOR,me); 
        me->move("/d/wulin/shanmen") ;
        tell_object(me,CYN"���ںڰ���ת�˼����䣬��֪������������ͬ��ɽ�š�\n"NOR);
   
        return 1;
}
