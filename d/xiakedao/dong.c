//Cracked by Roath
// /xiakedao/Dong1.c
// modified by aln 5 / 98

inherit __DIR__"no_pk_room";

int do_study(string arg);

void create()
{
	set("short", "ɽ��");
	set("long", @LONG
����һ�������ɽ�������ܵ�ǽ�ϲ��Ż�ѡ������ǽ��(wall)����
������Щʲ�ᡣ������������վ��������ۿ�(look)��
LONG );

	set("exits", ([
		"south" : __DIR__"",
	]));

	set("item_desc",([
	    "wall" : "ǽ�Ͽ���ʮ��������ÿһ���������Ų�ͬ���η�Ծ�����ơ�
��������Ŵӻ���ѧ������Ṧ��(study wall) \n",

	]));
	

}
void init()
{
        ::init();

	add_action("do_study", "study");
}
int do_study(string arg)
{	object me = this_player();
	int check;
	if ( !arg )
		return notify_fail( "����ѧʲ��?\n");
	if ( arg != "wall" )
		return notify_fail( "����ʵʵ study wall �ɡ�\n");

	if (!(int)me->query_temp("mark/ѧ1"))
	{	write("ÿ��ѧϰ��ľ��ͻ��ٶ�ʮ�㣬�����ľ�̫�;�����޷����С�\n");
		write("������ʵս����̫�ͣ�(�����Ṧ^3 > ����*10)������޷���ѧ�ˡ�\n");
		me->set_temp("mark/ѧ1", 1);
	}

	check = (int)me->query_skill("dodge",1)*(int)me->query_skill("dodge",1)*(int)me->query_skill("dodge",1);
	if (check < (int)me->query("combat_exp") * 10)
	{	write("�����ڵ�ʵս���鲻�㣬�޷���������Ṧ��\n");
	}
	else if ((int) me->query("jing") < 30)
	{	write("�㾫���޷����С�\n");
	}	
	else
	{	me->receive_damage("jing", 20, "������������");
	      me->improve_skill("dodge", (int)me->query_skill("literate")/5 + 1);
      	write("����������Ṧ����ļ������ѡ�\n");
	}
	return 1;
}
