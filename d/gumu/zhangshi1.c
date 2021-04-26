// Aug 30,2001
// Code by Yujie
// /gumu/zhangshi1.c
// update by april 2001.11.05
inherit ROOM;

void create()
{
	set("short","������");

	set("long",@LONG
���������ҵ�խ�棬ʯǽ(wall)������������Ÿ���ͼ�κ����֣���
��������Ҫ����
LONG);

	set("item_desc",(["wall" : "����ϸ�о��ţ�����ͼ���е�����ʹ��һ���Ʒ���ȭ����ϵĹ���Ů��\n"
		+"ʹ����һ��ȭ����ָ����ϵĹ��򣬰����ޱȡ��㿪ʼ��ϰ(yanxi)������\n"]));

	set("exits",([
		"south" : __DIR__"liangongshi1"
		]));

	set("cost",1);
	set("count",0);

	setup();

}

void init()
{
	add_action("do_yanxi", "yanxi");
}

int do_yanxi(string arg)
{
	object me = this_player();
	int cuff_lvl,strike_lvl,finger_lvl;
	
	if ( !arg )	return notify_fail( "��Ҫ����ʲô?\n");
	if ( arg != "wall" ) return notify_fail( "��Ҫ����ʲô?\n");

	if ( me->is_busy() ) return notify_fail("����æ���أ�\n");
	if( me->is_fighting() ) return notify_fail("���Ѿ���ս�����ˣ�ѧһ��ʵս����ɡ�\n");

	if ( (int)me->query_skill("literate", 1) < 1) {
		write("�����ֶ�����ʶ��ô����ѽ��������ѧ���Ļ�(literate)�ɡ�\n");
		return 1;
	}

	if ((int)me->query("jing") < 30 || me->query("jingli") < 30 ){
        write("���۵���ǽ�ϵ��ֶ���������ˣ�����ЪϢһ�°ɡ�\n");
		return 1;
	}

	me->receive_damage("jing", 20 ,"����ƣ������");
	me->receive_damage("jingli", 20 ,"����ƣ������");

	message_vision("$N������ǽ�ϵ�Ҫ����ʼ����ȭ�Ź���ľ��衭��\n", me);

	cuff_lvl = (int)me->query_skill("cuff",1);
	if ( cuff_lvl > 200 )
		write("ǽ��ȭ��Ҫ���ľ����㾡��������գ���Ҳ���ܴ��������ȭ���ˡ�\n");
	else if (cuff_lvl * cuff_lvl * cuff_lvl > (int)me->query("combat_exp") * 10)
		write ("���ʵս���鲻�㣬�޷����ȭ���ˡ�\n");
	else {
		me->improve_skill("cuff", me->query_int()/2);
		write("����ĥ��һ���ƺ��Ի���ȭ�������ĵá�\n");
	}

	if ( me->query("gender") == "����" ) {
		strike_lvl = (int)me->query_skill("strike",1);
		if ( strike_lvl > 200 )
			write("ǽ���Ʒ�Ҫ���ľ����㾡��������գ���Ҳ���ܴ����������\n");
		else if (strike_lvl * strike_lvl * strike_lvl > (int)me->query("combat_exp") * 10)
			write ("���ʵս���鲻�㣬�޷�����Ʒ��ˡ�\n");
		else {
			me->improve_skill("strike", me->query_int()*2/5);
			write("����ĥ��һ���ƺ��Ի����Ʒ������ĵá�\n");
		}
	}

	if ( me->query("gender") == "Ů��" ) {
		finger_lvl = (int)me->query_skill("finger",1);
		if ( finger_lvl > 200 )
			write("ǽ��ָ��Ҫ���ľ����㾡��������գ���Ҳ���ܴ��������ָ����\n");
		else if (finger_lvl * finger_lvl * finger_lvl > (int)me->query("combat_exp") * 10)
			write ("���ʵս���鲻�㣬�޷����ָ���ˡ�\n");
		else {
			me->improve_skill("finger", me->query_int()*2/5);
			write("����ĥ��һ���ƺ��Ի���ָ�������ĵá�\n");
		}
	}
	
	if ( query("count") < 20 ) add("count",1);
	else {
		me->start_busy(1);
		set("count",0);
	}
	return 1;
}

