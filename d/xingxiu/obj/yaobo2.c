// Code of ShenZhou
// 11/5/96. Ryu
// 30/12/98 Haowen
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
   add_action("do_apply", "apply");
   add_action("do_apply", "bu");
   add_action("do_hold", "hold");
   add_action("do_hold", "hold");			
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

//the following modified by haowen to provide poison on cloth

int do_hold(string arg)
{
	string me, what;
        object ob, obj=this_object();

        if( !arg
        ||      sscanf(arg, "%s", what)!=1 )
                return notify_fail("�����ʽ: hold/zhuang <��Ʒ> ��\n");

        ob = present(what, environment(this_player()));
        if( !ob )
                return notify_fail("����û��" + what + "����������\n");
	if( ob->query("race") == "����" || ob->query("race")=="����")
		{
		if(random(this_player()->query_skill("training",1)*10) > random(ob->query("combat_exp")))
			{    
			if (obj->query("poison"))
			       obj->set("poison",10+obj->query("poison"));
			else   obj->set("poison",10);
			message_vision(GRN"$N�͵ĳ��������񲧿�ס"+ob->query("name")+"��\n"NOR, this_player());
			message_vision(RED"$N�þ���ס���񲧣�һ������֮��û�˶������Ͻ��ջ����񲧣������Ѿ�����һ�㶾ҩ�ۣ�\n"NOR,this_player());
			obj->set("long",obj->query("long")+BLU"����������һЩ��ҩ�ۣ�\n"NOR);
			this_player()->add("neili",-50);
			ob->destory();
			}
		else message_vision(GRN"$N�͵ĳ��������񲧿���"+ob->query("name")+",��"+ob->query("name")+"����������ˡ�\n"NOR,this_player());
		
		return 1;
		}
	else return notify_fail("���"+ob->query("name")+"���²������ɶ�ҩ�ۣ�\n");
}

int do_apply(string arg)
{       string what;
        object ob, obj=this_object();
	function f;

        if(!arg || sscanf(arg,"%s",what)!=1)
                return notify_fail("��Ҫ��ʲô�����ϲ�����\n");
        if (!arg || !(ob = present(arg, this_player())))
                return notify_fail("������û��" + what + "��\n");

	if (!obj->query("poison"))
		return notify_fail("�㻹û������ҩ��\n");

        if (! ob->query("armor_prop/armor"))
                return notify_fail("��ô��������Ķ�ҩ�ɲ���ϹͿ��\n");

	if (ob->query("poison_amount") && this_player()->query_skill("poison", 1) < ob->query("poison_amount"))
		return notify_fail(ob->query("name")+"�϶����Ѿ���ǿ�ˣ��㻹�ǲ�Ҫ�ٲ����˰ɡ�\n");

	message_vision(RED"$NС������ذ�һЩ��ҩ����" +ob->query("name")+"�ϡ�\n"NOR, this_player());
	if (ob->query("poison_amount"))
		ob->set("poison_amount", obj->query("poison")/2 + ob->query("poison_amount"));
	else    ob->set("poison_amount", obj->query("poison")/2);
	ob->set("no_sell");
        obj->set("poison",obj->query("poison")/2);
	if (obj->query("poison")<=0)
		{
		obj->delete("poison");
		obj->set("long","һֻ������ҩ�������ʼ䷺����ɭɭ�����⡣\n");
		}
//	ob->set("long", ob->query("long") + BLU"�����ƺ�ι�о綾��\n"NOR);
	return 1;
}
