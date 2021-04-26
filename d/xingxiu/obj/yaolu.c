// Code of ShenZhou
// yaolu.c ҩ¯
// Kane

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIC"����ҩ¯"NOR, ({ "yao lu", "lu" }) );
	set_weight(300000);
	set_max_encumbrance(5000000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
                set("long",
"����һ��Լ��һ�˶�ߵ�ҩ¯������尾�Ÿ��ֶ���ҩ�ģ�ɢ��������ҩ����\n"
"��ϸһ�ţ�ҩ�����ƺ������Ŵ���������������֮��Ż��\n");
		set("value", 1000);
		set("material", "wood");
		set("no_get",1);
	}
	setup();
}

int is_container() { return 1; }

void init()
{
	add_action("do_put", "put");
	add_action("do_light", "light");
}

int do_put(string arg)
{
	object me, obj;
	string item, target; 
	int amount;

	me = this_player();

	if( !arg || sscanf(arg, "%s in %s", item, target) != 2 )
                return notify_fail("��Ҫ��ʲô�����Ž����\n");
                
        if( item == "all" ) {
		write("����һ��һ�����ɡ�\n");
		return 1;
	}
                                                                
	sscanf(item, "%d %s", amount, item);
	
	if( !objectp(obj = present(item, me)) )
		return notify_fail("������û������������\n");

	if( query_temp("corpse_in") )
		return notify_fail("��һ��ֻ�ܷ�һ��ʬ�塣\n");

	if( obj->query("id") != "corpse"
        && obj->query("name") != "����˿"
        && obj->query("name") != "���ߵ�"
        && obj->query("name") != "����"
        && obj->query("name") != "Ы�ӿ�"
        && obj->query("name") != "ɳ���" ) {
		write("�㲻����ҩ¯�������������\n");
		return 1;
	}
	if( obj->query("name") == "����˿" )
		add_temp("mark1", 1);
        if( obj->query("name") == "���ߵ�" )
                add_temp("mark2", 1);
        if( obj->query("name") == "����" )
                add_temp("mark3", 1);
        if( obj->query("name") == "Ы�ӿ�" )
                add_temp("mark4", 1);
        if( obj->query("name") == "ɳ���" )
                add_temp("mark5", 1);
	if( obj->query("id") == "corpse" )
		set_temp("corpse_in", 1);
}

int do_light(string arg)
{
	object  me = this_player();

	if (!present("fire", me))
		return notify_fail("��Ҫ��ʲô���\n");
/*
	if(!query_temp("mark1") || !query_temp("mark2")
	|| !query_temp("mark3") || !query_temp("mark4")
	|| !query_temp("mark5") || !query_temp("corpse_in") )
		return notify_fail("ҩ��Ʒ�ֲ��룡\n");
*/
        if (!id(arg))
                return notify_fail("��Ҫ��ȼʲô��\n");
	message_vision(HIG"$N��ȼ��ҩ¯�µĻ�ѣ�һ����ɫ���涸Ȼһ����\n"NOR,me);
	set("long", query("long") + CYN"����ð���������̡�\n"NOR);
	remove_call_out("burning1");
	remove_call_out("burning2");
	remove_call_out("burning3");
        call_out("burning1",2, me);
	call_out("burning2",4, me);
	call_out("burning3",6, me);
	return 1;
}

void burning1(object me)
{
	object *ob, obj;
	int i;

	ob = all_inventory(this_object());
	
	for(i=0; i<sizeof(ob); i++) {
/*
	if( ob[i]->query("name") == "����˿"
        || ob[i]->query("name") == "���ߵ�"
        || ob[i]->query("name") == "����"
        || ob[i]->query("name") == "Ы�ӿ�"
        || ob[i]->query("name") == "ɳ���" ) {
		obj = ob[i];
		destruct(obj);
		ob = all_inventory(this_object());
		}
*/
	if( ob[i]->query("id") == "corpse")
		ob[i]->set("name","������ʬ��");
	}

	message_vision(MAG"$N�в���ð��Ũ�̣�¯�и��ֶ��￪ʼ�����ڻ���\n"NOR,this_object());
}

void buring2(object me)
{
        object *ob, obj;
        int i,skill,extra;

        ob = all_inventory(this_object());

/*
	for(i=0; i<sizeof(ob); i++) {
	if( ob[i]->query("id") == "corpse")
		obj = ob[i];
	}
*/
	message_vision(HIB"$N�����̽�����ɢ��¯�е�ʬ�彥����С����ɫת����\n",this_object());
	obj = new("/d/xingxiu/obj/dushi");
	skill = me->query_skill("poison",1);
	extra = query_temp("mark1")+query_temp("mark2")+query_temp("mark3")+query_temp("mark4")+query_temp("mark5");
	obj->set("weapon_prop/damage", skill);
	obj->set("poison_effect", extra*3);
	obj->move(this_object());
}

void buring3(object m)
{
        object *ob;
        int i, extra;

	message_vision(YEL"$N�е�ʬ�彥�����ڷ�����ɢ����һ�����̣�\n"NOR,this_object());
        extra = query_temp("mark1")+query_temp("mark2")+query_temp("mark3")+query_temp("mark4")+query_temp("mark5");
        ob = all_inventory(environment(this_object()));
	for(i=0; i<sizeof(ob); i++) 
		ob[i]->apply_condition("xx_poison", extra);

}
