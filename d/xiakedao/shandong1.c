//Cracked by Roath
// /xiakedao/Dong2.c
// modified by aln 5 / 98

inherit __DIR__"no_pk_room";

void create()
{
	set("short", "ɽ��");
	set("long", @LONG
����һ�������ɽ�������ܵ�ǽ�ϲ��Ż�ѡ��������ż���ľ׮(zhuang),
һ������С����������������ȭ�����Ĵ���һ��ľ׮(hit zhuang)��
LONG );

	set("exits", ([
		"south" : __DIR__"",
	]));

	set("item_desc",([
	    "zhuang" : "ľ׮���°������ε����ڵ��£��ϰ���װ������ľ֦��\n"
			 "�����������ȭȥ������һ��ľ׮ѧ�������(strike zhuang) \n",

	]));
	

}
void init()
{
        ::init();

	add_action("do_strike", "strike");
}

int do_strike(string arg)
{	object me = this_player();
	int check;
	if ( !arg )
		return notify_fail("ʲ��?\n");
	if ( arg != "zhuang" )
		return notify_fail( "����ʵʵ strike zhuang �ɡ�\n");

	if (!(int)me->query_temp("mark/ѧ1"))
	{	write("ÿ��ѧϰ��ľ��ͻ��ٶ�ʮ�㣬�����ľ�̫�;�����޷����С�\n");
		write("������ʵս����̫�ͣ�(����ȭ��^3 > ����*10)������޷���ѧ�ˡ�\n");
		me->set_temp("mark/ѧ1", 1);
	}

	check = (int)me->query_skill("cuff",1) * 
	        (int)me->query_skill("cuff",1) * 
	        (int)me->query_skill("cuff",1);
	if (check < (int)me->query("combat_exp") * 10)
	{	write("�����ڵ�ʵս���鲻�㣬�޷��������ȭ����\n");
	}
	else if ((int) me->query("jing") < 30)
	{	write("�㾫���޷����С�\n");
	}	
	else
	{	me->receive_damage("jing", 20, "������������");
	      me->improve_skill("cuff", (int)me->query_skill("literate")/5 + 1);
      	write("���������ȭ������ļ������ѡ�\n");
	}
	return 1;
}
