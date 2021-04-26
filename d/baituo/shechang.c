// Code of ShenZhou
// shechang.c �߳�
// ���յ��������������ߵĵط���
// maco 4/15/2000

#include <ansi.h>
inherit ROOM;

int POISON = 0;
int AMOUNT = 0;
int MANAGE = 0;

int do_count();

void create()
{
	set("short", "�߳�");
	set("long", @LONG
���ǰ���ɽׯ�������߳������߹Ȳ�׽���Ķ��߶��ڴ���������
��Χ���������ߵĻ�ɫԲǽ��ǽ������Բ���Σ��⻬�޷졣���ｨ��
������ѣ��ɰ���ɽׯ�е���ū����������綾�Ĺ��߾����ڴ�
�ӽ����á�
LONG
	);

	set("exits", ([ 
	    "west" : __DIR__"road5",
            "east" : __DIR__"dushi",
	]));
	set("no_fight", 1);
	set("objects", ([ 
	    "/d/baituo/npc/shenu" : 1,
	 ]) );
	set("cost", 2);
	setup();
}

void init()
{
	add_action( "do_count", "count" );
	add_action( "do_manage", "manage" );
	add_action( "do_check", "check" );
	add_action( "do_return", "return");
}

int do_manage()
{
	object me = this_player();
	int asp;

	if( me->query("family/family_name") != "����ɽ" )
		return notify_fail("�ܱ��˼ҵ����¸��\n");

	if( me->query("family/master_name") != "ŷ����")
		return notify_fail("�㻹û���ʸ������Լ�����Ⱥ��\n");

	if( (int)me->query_skill("poison",1) < 100 )
		return notify_fail("��Զ����˽ⲻ��͸������û�а취�������ߡ�\n");

	if( me->query("baituo/new_breed_time") )
		return notify_fail("�ȵ��ϻ��������ߵĳɹ������ɡ�\n");

	MANAGE = 1;
	asp = do_count();
	MANAGE = 0;

	if(! asp || asp == 0 )
		return notify_fail("");

	message_vision("\n$N����Ⱥ�Ͻ����ѣ��Ը���ū�ú�������\n", me);
	if( wizardp(me) ) write("��Щ�������������֣�Ԥ�ڿ�ӵ��"+asp+"�Ķ��ԡ�\n");

	me->set("baituo/new_breed", asp);
	me->set("baituo/new_breed_time", time());
	me->add("baituo/manage", 1);
	me->delete("baituo/checked_snake");
	return 1;
}

int do_count()
{
	mapping snakes;
	string *names, str;
	int flag, average, i, num, sort, sort2, per;
	object me, obj; 
	mixed *inv;

	me = this_player();
	obj = this_object();
	inv = all_inventory(obj);

	if( me->query("family/family_name") != "����ɽ" )
		return notify_fail("�ܱ��˼ҵ����¸��\n");

	if( (wizardp(me) && me->query("env/snake_test") == "YES" )|| me->query_temp("test")) 
		flag = 1;

	inv = map_array(inv, "snake_list", this_object() );

	str = sprintf("���߳�����\n%s\n", implode(inv, "") );

	if(flag) write(str);

	str = "";

	if( mapp(snakes = obj->query("snakes")) ) {
		names = keys(snakes);
		for(i=0; i<sizeof(names); i++)
		names -= ({ 0 });

		if( !sizeof(names) || sizeof(names)==0 ) {
		write("�����߳�����û���㲶�����ߡ�\n");
		return notify_fail("");
		}

		else if( sizeof(names)==1 )
			str += "�߳���Ψһ���㲶׽����������" + names[0] + NOR + "��\n";

		else str += sprintf("�߳������㲶׽��������%s�֣��ֱ���%s��%s��\n", 
			chinese_number(sizeof(names)),
			implode(names[0..sizeof(names)-2], "��"), 
			names[sizeof(names)-1]);

		//����ÿ���ߵ�����
		for (i = 0; i < sizeof(names); i++) {
			num = query("snakes/"+names[i]);
			sort = query("snakes_poison/"+names[i]);
			per = 110-num*5;
			sort2 = sort*per/100;

			if(flag) printf("%s�ܹ���%s�����߶���ֵ%d������%d%%֮����%d��\n", 
			names[i], chinese_number(num), sort, per, sort*per/100 );

			POISON += sort2;
		}

		average = POISON / AMOUNT;
		
		if(flag)
		str += sprintf("����%s���ߣ��߶��ܺͣ�%d �߶�ƽ��ֵ��%d��\n"NOR,
		chinese_number(AMOUNT), POISON, average);


		if ( MANAGE == 0 ) write(str);
	}
	else {
		write("�����߳�����û���㲶�����ߡ�\n");
		return notify_fail("");
	}

	if(average < 100) {
		write("��Щ���ַ�ֳ�������ߣ����Ի������˵㡣\n");
		return notify_fail("");
	}

	if ( sizeof(names) < 3 ) { 
		write("Ҫ�������ߣ�����Ҫȡ���ֲ�ͬ��������ֳ��\n");
		return notify_fail("");
	}
	else if ( MANAGE == 1 ) {  //��manageָ���ȡʱ��һ�߼���һ��������ʧ
		inv = all_inventory(obj);
		for (i = 0; i < sizeof(inv); i++) 
		if (inv[i]->query("race") == "����" 
		&& inv[i]->query("caught") == me->query("id") ) destruct(inv[i]);
	}

	if( MANAGE == 0 && average > me->query("baituo/breed") 
	&& me->query("baituo/breed") > 100 )
		write(HIB"�㰵��˼������������Щ�ߣ�Ҳ��������������Ը�ʤ�����Ĺ��ߡ�\n"NOR);

	POISON = 0;
	AMOUNT = 0;
	delete("snakes");
	delete("snakes_poison");

	return average;

}

string snake_list(object obj, int flag)
{
	int sp = obj->query("snake_poison");
	string str;

	if ( obj->query("race") == "����" 
	&& obj->query("caught") == this_player()->query("id") ) {
		str = sprintf("%-24s�� ���飺%-10d  �߶���%3d  \n" NOR,
		obj->name() +"("+obj->query("id")+")", obj->query("combat_exp"), sp);

		AMOUNT += 1;
		add("snakes/"+obj->name(), 1);
		add("snakes_poison/"+obj->name(), sp);

		if ( !flag )
			str = "  " + str;
		else
			return 0;
	}
	else str = "";

	return str;
}

int do_check()
{
	object me = this_player();
	
	if( !wizardp(me) )return 0;

	write( sprintf( 
	"breed: %d, new_breed: %d, new_breed_time: %d, checked_snake: %d \n"
	"passed time: %d, manage: %d, snake_amount: %d \n" ,
	me->query("baituo/breed") ,
	me->query("baituo/new_breed") , 
	me->query("baituo/new_breed_time"), 
	me->query("baituo/checked_snake"), 
	time() - me->query("baituo/new_breed_time"), 
	me->query("baituo/manage"), 
	me->query("baituo/snake_amount")  ) );
	return 1;
}

int do_return(string arg)
{
	object me, snake; 
	
	me = this_player();

	if( !arg || arg=="" ) return 0;

	if( !objectp(snake = present(arg, me)) && !objectp(snake = present(arg, environment(me)))) 
		return notify_fail("��Ҫ�������߻����ѣ�\n" );

	if( snake->query("race") != "����" ) 
		return notify_fail(snake->name()+"��"+snake->query("race")+"���ɲ������࣡\n");

	if( snake->query("who_breed") != me->query("id") )
		return notify_fail("����"+snake->name()+"���������������ġ�\n" );

	message_vision("$N��$n�ϻ��������\n", me, snake);

	if(snake->name() == "С����")
	me->add("baituo/snake_amount", 1);

	destruct(snake);
	return 1;
}
