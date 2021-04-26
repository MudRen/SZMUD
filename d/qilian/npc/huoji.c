// Code of ShenZhou
// huoji. ���

inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("���", ({ "huo ji" }));
	set("str", 20);
	set("gender", "����");
	set("age", 18);
	set_max_encumbrance(100000000);
	set("long", "��������Ļ�ƣ����ڵ���æ��æ�⡣\n");
	set("combat_exp", 250);
	set("attitude", "friendly");
	set("vendor_goods", ({
		"/d/qilian/obj/goupi",
		"/d/qilian/obj/pi-beixin",
		DRUG_D("gaoyao"),
	}));

	setup();
}

void init()
{
	::init();
        add_action("do_list", "list");
        add_action("do_buy", "buy");
//	add_action("do_make", "make");
}

int accept_object(object who,object ob)
{
        int a;
	object money, cloth;
	string *beast_list = ({
	"÷��¹",
	"Ұ��",
	"�ϻ�",
	"����",
	"С��",
	"ĸ��",
	"����"
	});
	a = ob->query("combat_exp");
 if ( member_array(ob->query("victim_name"), beast_list) != -1 )

 	{
	call_out("destroy", 1, ob);
	command("say ��ͷ"+ob->query("victim_name")+"ֵ���˼�����Ǯ��");	
	money=new("/clone/money/silver");
	money->set_amount((int)a/100);
	if ((int)a/100 > 300)
	money->set_amount(300);
	money->move(who);
	say("��Ƶݸ��㼸�����ӣ�˵�������պá�\n");
	return 1;	
	}
	if( ob->value() >= 1000 )
	{
	who->set_temp("cloth", 2);
	return 1;
	}
}
void destroy(object ob)
{
	if (ob);
        destruct(ob);
        return;
}

int do_make(string arg)
{
        object me, obj, ob;
        string item; 
        int amount;
	string *beast_list = ({
        "÷��¹",
        "Ұ��",
        "�ϻ�",
        "����",
        "С��",
        "ĸ��",
        "����"
        });

	
        me = this_player();
        ob = new("/d/qilian/obj/leather.c");

        if( !arg || sscanf(arg, "%s into cloth", item) != 1 )
                return notify_fail("��Ҫ��ʲô���������·���\n");
	if (me->query_temp("cloth") < 1)
		return notify_fail("��û��Ǯ���˼Ҳ���������·���\n");         
        if( item == "all" ) {
                write("����һ��һ�����ɡ�\n");
                return 1;
        }
                                                                
        sscanf(item, "%d %s", amount, item);
        
        if( !objectp(obj = present(item, me)) )
                return notify_fail("��Ҫ��˭ʲô������\n");

        if( obj->query("id") != "corpse"){
                write("�㲻�ܽ��������������·���\n");
                return 1;
        }
        if ( member_array(ob->query("victim_name"), beast_list) != -1  )
	{
        message_vision("$N��"+obj->query("name")+"�����˵���Ļ�ǡ�\n",
me);

        message_vision("$N�ӵ����нӹ���һ��Ƥ�£�\n",
me);
        ob->set("name", obj->query("victim_name")+"Ƥ����");
        ob->set("armor_prop/armor",(int)obj->query("combat_exp")/1000);
	ob->move(me);
        destruct(obj);
	me->delete_temp("cloth");
	        
        return 1;
}
}

