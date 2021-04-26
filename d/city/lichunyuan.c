// Code of ShenZhou
// Room: /city/lichunyuan.c
// YZC 1995/12/04 

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", GRN"����Ժ"NOR);
	set("long", @LONG
��һ�߽�����һ�۾Ϳ���������ǽ�Ϲ���һ��������ͼ(tu)��һ���Ӿ�����
������ʲô�ط������ڵ����ŵƽ�ʣ������˱ǡ�������������������Ů�˷�
վ���Զ��㷢����Ц������Τ�����������¡�ǰǰ����к��ſ��ˡ���¥�ϴ���
������������ε�������
LONG
	);

	set("objects", ([
                CLASS_D("gaibang") + "/kongkong" : 1,
                __DIR__"npc/wei" : 1,
                __DIR__"npc/guinu" : 1,
//              "kungfu/class/shenlong/shou" : 1,
	]));

	set("item_desc", ([
		"tu" :
"                                      ��        ��          ��             
                                    ����        ��          ��
      ����������  ���С�����        ����      ����          ����
    ����������    ����������  ����������  ������ء�  �������ة�


   ��       ��    ������                 ��                  ��
   ��       ��    ������       ������  ����                  ��
   �� ���Щ���    �����ੴ   ��������������          ��С�����
   ��   ������    ��  ��                 ��            ��  ����
	\n"]));

	set("exits", ([
		"west" : __DIR__"nandajie3",
		"up" : __DIR__"lichun2",
	]));

	set("cost", 0);
	setup();
//	replace_program(ROOM);
}

void init()
{
	add_action("do_order", "order");
}


int do_order(string arg)
{
        object me = this_player();
        object victim;
        string arg1, arg2, arg3, msg;

        if (!arg)
                return notify_fail("��Ҫ����ʲô�ˣ�\n");
/*
        if( sscanf(arg, "%s %s %s", arg1, arg2, arg3) < 2 )
                return notify_fail("ָ�����\n");
*/
        sscanf(arg, "%s %s %s", arg1, arg2, arg3);
        victim = present(arg1,environment(me));

        if (!victim)
                return notify_fail("���ﲢ�޴��ˣ�\n");

        if (!living(victim))
                return notify_fail("�ⲻ�ǻ��\n");

        if (victim == me) return notify_fail("�αض��һ�٣�\n");

	if (!victim->query("hooker") )
		return notify_fail("������Ժ����Ĺ������������˵�ɡ�\n");

	if (!me->query_temp("money_given"))
		return notify_fail("��ү����û��Ǯ�أ�\n");

	if (!arg2) 
		return notify_fail("��Ҫ��������ʲô��\n");

	switch(random(3)) {
	case 0:
		msg = "$N�ٺ���Ц�˼�������ƤЦ���Ķ�$n˵��";
		break;
	case 1:
		msg = "$N������Ц�˼������װͰ͵Ķ�$n˵��";
		break;
	case 2:
		msg = "$N�Ǻ�Ц�˼���������Ĵս�$n˵��";
		break;
	}

        message_vision(CYN+msg + arg2 + " " + arg3+"�ɡ�\n"NOR, me, victim);
        
	if( !arg3 )
                EMOTE_D->do_emote(victim, arg2);
        else    EMOTE_D->do_emote(victim, arg2, arg3);

	me->delete_temp("money_given");
        return 1;
}

int valid_leave(object me, string dir)
{
    if (present("guinu",environment(me)) && 
                me->query("hooker")) {
       message_vision("��ūһ�Ѿ�ס$N��ȹ�ߣ����Ѿ�������Ժ�����ˣ����ӿͱ����ޣ�\n",
                me);
       return notify_fail("\n");
    }
    else
        return :: valid_leave(me,dir);
}
 

