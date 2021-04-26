// Code of ShenZhou
// maco

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
���ǰ���ɽׯ�ĳ�����������һ�������һ��ˮ�ף�����ɽׯ����ʦ
���Ҷ����Ů�ǿ����������ˮ(drink) �������Ｘ���Ů�������η���
��ֻҪׯ��������һ�зԸ�(order)���������Ƽ���������
LONG
	);
	set("exits", ([ 
	    "northwest" : __DIR__"liangongfang",
	    "northeast" : __DIR__"road2",

	]));
	set("resource/water", 1);
	set("no_fight", 1);
	set("objects", ([ 
	    "/d/xingxiu/obj/shegeng" : 1,
	    "/d/xingxiu/obj/kaoyang" : 1,
	    __DIR__"npc/binu" : 1,
	 ]) );
	set("cost", 0);
	setup();
}

void init()
{
	add_action("do_drink", "drink");
	add_action("do_order", "order");
}
int do_drink(string arg)
{
	int current_water;
	int max_water;
	object me;

	me = this_player();
	current_water = me->query("water");
	max_water = me->query("str")*10 + 100;
	
	if (me->query("family/master_id") == "ouyang feng" ) 
		return notify_fail("��Ϊ��ׯ����ſ��ˮ���Ϻ�ˮ����������ʧ�����\n");

	if (current_water<max_water) {
	    me->set("water", current_water + 30);
	    message("vision", me->name()+"ſ�ڴ�ˮ���Ϲ�ཹ�ཹ��˼���ˮ��\n"
	    , environment(me), ({me}) );
	    write("��ſ�ڴ�ˮ���Ϲ�ཹ�ཹ��˼���ˮ��\n");
	}
	else write("�Ů��ֵص����㣬�������ֿ��죬������Ц���������Ӷ����˻��ȣ�\n");

	return 1;
}


int do_order()
{
	object ob1, ob2, *inv, me = this_player();
	int food_ind, water_ind, f, w, i;
	mapping myfam;

	myfam = (mapping)me->query("family");
	if ( !myfam || myfam["family_name"] != "����ɽ" )
		return notify_fail("�㲻�ǰ���ɽׯ���ˣ�������ȡʳ�\n");


	inv = all_inventory(me);
	for (i=0; i<sizeof(inv); i++) {
		if (inv[i]->query("bt_food") && inv[i]->value() >= 0) f++;
		if (inv[i]->query("bt_liqueur") && inv[i]->value() >= 0) w++;
	}

	food_ind = me->query("food");
	water_ind = me->query("water");

	if ( (int)me->max_food_capacity()-food_ind < 10
	&& (int)me->max_water_capacity()-water_ind < 10 )
		return notify_fail("���Ѿ��Ա������ˣ��ɱ�����ʳ��\n");

	if( (f && w) 
	|| (f && (int)me->max_water_capacity()-water_ind < 10 ) 
	|| (w && (int)me->max_food_capacity()-food_ind < 10) )
		return notify_fail("�Ȱ����еľƲ˳���ɡ�\n");

	message_vision("$N����ָߵߵ���ӣ��е���׼��Щ�Ʋ�����\n", me);

	if (me->query("family/master_id") == "ouyang feng" ) {
	
	if(!f) {
	   switch(random(4)) {
	   case 0:
		ob1 = new("/clone/food/yangrou");
		break;
	   case 1:
		ob1 = new("/d/xingxiu/obj/zhuafan");
		break;
	   case 2:
		ob1 = new("/d/xingxiu/obj/xiangli");
		break;
	   case 3:
		ob1 = new("/d/xixia/obj/yangrou");
		break;
		}
	   	ob1->set("bt_food",1);
		ob1->move(me);
		message_vision("�Ů�����Ϸ���һ"+ob1->query("unit")+ob1->name()+"�����������������á�\n", me);
		}
	if(!w) {
		ob2 = new("/d/baituo/obj/liqueur");
		ob2->set("bt_liqueur",1);
		ob2->move(me);
		message_vision("�Ů��$N����һ���ơ�\n", me);
		}
	}
	else if (me->query("family/master_id") == "ouyang ke" ) {
	message_vision("�Ůҡ��ҡͷ������˵����"+RANK_D->query_respect(me)+"�����Ҫׯ��������ָʾ���С�\n", me);
	}
	else {
	message_vision("�������Ů����Ȼ��æ���ģ�������ȫû�˰�$N�Ľ��µ�һ���¡�\n", me);
	}
	return 1;
}

int valid_leave(object me, string dir)
{
	object *inv;
	int i, f, w;
	inv = all_inventory(me);
	for (i=0; i<sizeof(inv); i++) {
		if (inv[i]->query("bt_food") ) f++;
	}

	if ( (f>0) ) 
		return notify_fail("�Ա������˻�Ҫ����Ʋˣ�����Ѱ���ɽׯ����ɽ����\n");

	return ::valid_leave(me, dir);
}
