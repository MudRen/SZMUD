// By xuanyuan
// road: /zhongnan/lianggongshi2.c

inherit ROOM;
#include <ansi.h>
int do_study(string);

void create()
{
        set("short","������");

        set("long",@LONG
��ʯ�Һ�������ʯ���Ǵ����Գƣ����ִ����෴�����Ǳ�����խ����Բ����,
�Ҷ�(shibi)Ҳ�ǿ�������������.
LONG);

        set("item_desc",(["shibi" : "
��������˵����ʯ�Ҿ��Ǳ���ʼ�棬�ֳ�Ӣ������ĵط������겻֪
Ϊʲ�ᣬʦ�������Ĺ������һ��ʯ�ң�������̵ľ����ƽ�ȫ����书
�ľ��С�
\n",]));

        set("exits",([ "west" : __DIR__"lianggongshi1",

                      ])
           );
	  set("cost",1);

        setup();

}

void init()
{
	add_action("do_study", "study");
	add_action("do_study", "du");
	add_action("do_study", "lingwu");
}

int do_study(string arg)
{
	object me;
        mapping fam;

	me = this_player();

	if ( !arg || arg != "shibi" )
		return notify_fail("ʲô��\n");

        if (!mapp(fam = me->query("family")) || (string)me->query("family/family_name") != "��Ĺ��") 
		return notify_fail("�㲻�ǹ�Ĺ���ӵܣ����򲻵�ʯ���������书�İ��\n");

	if ( (int)me->query_skill("literate", 1) < 1)
		return notify_fail("���Ǹ���ä����ѧ���Ļ�(literate)�ɡ�\n");

	if ( (int)me->query_skill("yunu-jue", 1) < 60)
		return notify_fail("�����Ů��ʮ�ľ���򲻹����޷���������ѧϰʯ���ϵ��书��\n");

	if ( !me->query("family/master_name")) 
		return notify_fail("��û��ʦ����ָ�㣬������ʯ�������̵ĸ����书��\n");

	if ( me->query("jing") < 80)
		return notify_fail("��ľ���������\n");

	me->receive_damage("jing", random(80), "�����ʴ�����");

	message_vision("$N��ר���ж�ʯ���ϵ��书�ĵá�\n", me);

	switch( random(3) ) 
	{
	    case 0:
		if ( (int)me->query_skill("yunu-xinjing", 1) < 150)
		{
			me->improve_skill("yunu-xinjing", me->query_int());
			write("�����ʯ����ĥ��һ�ض����ƺ�����Ů�ľ��е��ĵá�\n");
			me->set_temp("shibi2_learned",1);
		}
	    case 1:
		if ( (int)me->query_skill("yunu-jianfa", 1) < 120)
		{
			me->improve_skill("yunu-jianfa", me->query_int());
			write("�����ʯ����ĥ��һ�ض����ƺ�����Ů�����е��ĵá�\n");
			me->set_temp("shibi2_learned",1);
		}
	    case 2:
		if ( (int)me->query_skill("yunu-jue", 1) < 100)
		{
			me->improve_skill("yunu-jue", me->query("int"));
			write("�����ʯ����ĥ��һ�ض����ƺ�����Ů��ʮ�ľ��е��ĵá�\n");
			me->set_temp("shibi2_learned",1);
		}
	    case 3:
		if ( (int)me->query_skill("whip", 1) < 100)
		{
			me->improve_skill("whip", me->query_int());
			write("�����ʯ����ĥ��һ�ض����ƺ��Ի����޷��е��ĵá�\n");
			me->set_temp("shibi2_learned",1);
		}
	    case 4:
		if ( (int)me->query_skill("sword", 1) < 100)
		{
			me->improve_skill("parry", me->query_int());
			write("�����ʯ����ĥ��һ�ض����ƺ��Ի��������е��ĵá�\n");
			me->set_temp("shibi2_learned",1);
		}
	}

	if ( !me->query_temp("shibi2_learned") )
	{
		write("�����ʯ����ĥ��һ�ض�������������˵��̫��ǳ�ԣ�������˵�Ѻ��������ˡ�\n");
	}
	return 1;
}
