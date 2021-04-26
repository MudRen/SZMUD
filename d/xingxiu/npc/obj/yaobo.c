// Code of ShenZhou
// 11/5/96. Ryu 
inherit F_UNIQUE;
inherit ITEM;
#include <ansi.h>
int do_put(string);
int do_squeeze(string);
int do_coat(string);
void setup()
{}


void create()
{
        set_name(BLU "����" NOR, ({"lanyu bo", "yao bo", "bo"}));
        set_weight(15000);
        set_max_encumbrance(1000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "ֻ");
                set("long", "һֻ������ҩ�������ʼ䷺����ɭɭ�����⡣\n");
                set("value", 7000000);
        }
	::create();
}
int is_container() { return 1; }
void init()
{
   add_action("do_put","put");
   add_action("do_squeeze", "squeeze");
   add_action("do_squeeze", "ji");
   add_action("do_coat", "coat");
   add_action("do_coat", "tu");
}
int do_put(string arg)
{
	object ob, obj, me = this_player();
	string item, target;
        int amount;
        int check, wait_time = 0;
	remove_call_out("open_up");
        if( !arg || sscanf(arg, "%s in %s", item, target) != 2 )
                return notify_fail("��Ҫ��ʲô�����Ž����\n");

        if( item == "all" ) {
                write("����һ��һ�����ɡ�\n");
                return 1;
        }

        sscanf(item, "%d %s", amount, item);

        if( !objectp(obj = present(item, me)) )
                return notify_fail("��Ҫ��˭ʲô������\n");
	if( obj->query("no_drop") ) {
                write("�������������뿪�㡣\n");
                return 1;
        }
	if( obj->name()=="���ߵ�"){ 
                message_vision( sprintf(HIY "$N��һ%s%s�Ž�%s��\n" NOR,
                        obj->query("unit"), obj->name(),
                        this_object()->name()),me );
		call_out("destroy_it", 1, obj);
		if (me->query_skill("poison", 1) >= 120){
		this_object()->set("san", 1);
		}
		return 1;
	}
	if( obj->query("id")=="shachong ke" ){
                message_vision( sprintf(HIY "$N��һ%s%s�Ž�%s��\n" NOR,
                        obj->query("unit"), obj->name(),
                        this_object()->name()),me );
                call_out("destroy_it", 1, obj);
                if (me->query_skill("poison", 1) >= 120){
                if (this_object()->query("san") == 1)
                this_object()->set("san", 2);
                }
                return 1;
        }
	if( obj->query("id")=="xiezi ke" ){
                message_vision( sprintf(HIY "$N��һ%s%s�Ž�%s��\n" NOR,
                        obj->query("unit"), obj->name(),
                        this_object()->name()),me );
                call_out("destroy_it", 1, obj);
                if (me->query_skill("poison", 1) >= 120){
                if (this_object()->query("san") == 2)
                this_object()->set("san", 3);
                }
                return 1;
        }
	if( obj->name()=="����˿" ){
                message_vision( sprintf(HIY "$N��һ%s%s�Ž�%s��\n" NOR,
                        obj->query("unit"), obj->name(),
                        this_object()->name()),me );
		call_out("destroy_it", 1, obj);
		if (me->query_skill("poison", 1) >= 120){
		if (this_object()->query("san") == 3)
                this_object()->set("san", 4);
		}
		return 1;
        }
	if( obj->name()=="����" ){
                message_vision( sprintf(HIY "$N��һ%s%s�Ž�%s��\n" NOR,
                        obj->query("unit"), obj->name(),
                        this_object()->name()),me );
		call_out("destroy_it", 1, obj);
                if (this_object()->query("san") == 4 
		&& me->query_skill("poison", 1) >= 120){
	if ( interactive(me)) {
		remove_call_out("open_up");
           call_out("open_up", random(10)+10, this_object());
		}
	}
	return 1;
	}
	else if (present(item, me) != this_object()){
                write(obj->name()+"�����񲧶���˵̫���ˡ�\n");
                return 1;
        }
}
int open_up()
{
	object ob, obj = this_object();
	ob=new("/d/xingxiu/obj/sanxiao");
        ob->move(obj);
	obj->set("san", 0);
	return 1;
}
int do_squeeze(string arg)
{
	string me, what;
        object ob, obj;

        if( !arg
        ||      sscanf(arg, "%s to %s", what, me)!=2
        ||      !id(me) )
                return notify_fail("�����ʽ: squeeze <��Ʒ> to <��Ʒ>��\n");

        ob = present(what, this_player());
        if( !ob )
                return notify_fail("������û��" + what + "����������\n");
	if( ob->query("name") != "����")
		return notify_fail("��������������Ｗ��ʲô��\n");
	obj=new("/d/xingxiu/obj/fushe-xian");
	obj->move(this_object());
	add("venom", 1);
	message_vision(GRN"$N��ס���ߵ���򦣬����һЩ���ѣ������񲧽�ס��\n"NOR, this_player());
	if (query("venom")>random(7)){
	message_vision("���߱�$N�����ˡ�\n", this_player());
	ob->die();
	}
	return 1;
}
int do_coat(string arg)
{
        object ob, obj;
	function f;

        if (!arg || !(ob = present(arg, this_player())))
                return notify_fail("��Ҫ��ʲô��\n");

	if (!present("venom", this_object()))
		return notify_fail("��Ҫ��ʲô��\n");

        if (! ob->query("weapon_prop/damage"))
                return notify_fail("�����ѿɲ���ϹͿ��\n");

	if ( ob->query("poison_applied") > 0)
		return notify_fail("�����������Ѿ�ι�ж�ҩ�ˡ�\n");

	if (this_player()->query_skill("poison", 1) < 100)
		return notify_fail("�㻹û��������������ι���ļ��ܡ�\n");

	message_vision(RED"$NС������ذ�һЩ������Ϳ��" +ob->query("name")+"�ϡ�\n"NOR, this_player());
	ob->set("poison_applied", this_player()->query_skill("poison", 1)/3);
	ob->set("no_sell");
	ob->set("long", ob->query("long") + BLU"�����ƺ�ι�о綾��\n"NOR);
	obj = present("venom", this_object());	
	call_out("destroy_it", 1, obj);
	return 1;
}
void destroy_it(object obj)
{
        destruct(obj);
        return;
}

