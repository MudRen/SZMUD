// Code of ShenZhou
// smith.c
// Ryu, modified on 3/20/97
//Kane, modified on 6/98

#include <ansi.h>
inherit NPC;
inherit F_VENDOR;
int ask_me();
int do_sell(string);
int do_hit(string);
void create()
{
	set_name("������", ({ "feng", "smith" }) );
	set("gender", "����" );
	set("age", 53);
	set("long", 
"���������ǳ��������������������ˣ�˫�۱��̻�޹���ֺ���ϸ��\n"
"���Ȳзϣ������³���һ�����ȡ�\n");
	set("combat_exp", 500000);

        set("str", 33);
        set("dex", 17);
        set("con", 28);
        set("int", 27);
	set("shen_type", 1);
	set("neili", 1000);
        set("max_neili", 1000);
	set("max_qi", 1800);
        set("max_jing", 800);
        set("jiali", 50);
        set("score", 5000);
        set_temp("apply/armor", 100);

        set("attitude", "friendly");
        set_skill("dodge", 80);
	set_skill("hammer", 150);
	set_skill("parry", 80);
        set_skill("force", 80);
	set_skill("bitao-xuangong", 80);
	set_skill("luoying-shenfa", 80);
	set_skill("strike", 80);
	set_skill("luoying-shenjian", 80);
	set_skill("qimen-dunjia", 80);

	map_skill("force", "bitao-xuangong");
        map_skill("parry", "luoying-shenjian");
/*
        map_skill("strike", "luoying-shenjian");
        map_skill("dodge", "luoying-shenfa");

        prepare_skill("strike", "luoying-shenjian");
*/

        set("vendor_goods", ({
                __DIR__"obj/hammer",
		"/clone/weapon/caidao",
        }));
//        set("chat_chance", 50);
//	set("chat_msg_combat", (: add_hammer :));
	set("inquiry", ([
		"name": "С���շ룬�����˶����ҷ�������",
		"here": "������С�˺��ڵ����ӣ�С�˾�ס����ߵ����ӡ�",
		"��ͷ": "��ͷ... ��Ǹ����ͷ�Ѿ�������...",
		"����": "������С������������������ã�һ��ֻҪ������Ǯ��",
		"��"  : 
"Ŷ�����Ǹ���ɽ�������Ŵ�ģ�С�����������£�����û�˷��ǿ������\n"
"�ţ�������ǰ��������ͽ��ɽȥ�ˣ���֪ʲ��ʱ��Ż�������ȡ����",
		"ȡ��": "С��һ��Ҫ���������ŵ����Ų��ܸ�����",
		"��Ĭ��" : "�������������С���Ѿ��þ�û����������...",
		"���Ŷݼ�" : "�Ƕ���Сʱ��ѧ�ģ�ƽʱû�½���ư��ˡ�",
		"����" : (: ask_me :),
		"����" : (: ask_me :),
	]) );
//	create_family("�һ���", 2, "����");
	setup();
	carry_object(__DIR__"obj/hothammer")->wield();
}
void init()
{
        ::init();
        add_action("do_buy", "buy");
	add_action("do_list", "list");
	add_action("do_sell", "sell");
	add_action("do_hit", "hit");
	add_action("do_hit", "da");
}
int ask_me()
{
	say("����������һ����˵������ɻ�ã�������������������ˣ�����ȥ�Ҽ�ʮ��������ɡ�\n");
	this_player()->set_temp("marks/��", 1);
	return 1;
}	


int accept_object(object who, object ob)
{
	object sword;
        if ((string)ob->query("name")=="����" && (string)ob->query("id")=="letter" && !userp(ob)) {
              if(!query("yl_trigger")) {
	sword = new(__DIR__"obj/youlong");
        if (!sword){
        say("������˵�����ǽ��类�����ˣ���������һ���ţ�һ���Ǽٵġ�\n");
	call_out("destroy", 1, ob);
	return 1;
	}
		say(
"������˵������ѽ��䲻���ۣ���Ҳ��С�˵���Ѫ������Ե��������š�\n"
"��������" + sword->query("name") + "������" + who->query("name") + "��\n");
		sword->move(who);
		command ("rumor "+who->query("name")+"Ū����һ����������");
                set("yl_trigger", 1);
              }
           else say("��������Ҳ��̧��˵����Ҫ���Լ���ȥ�á�\n");
        call_out("destroy", 1, ob);
	return 1;
	}

        if( (string)ob->query("name")=="������") {
		if( !query("accept_bagua") ) return 0;
		call_out("accept_obj", 2, who, ob);
		return 1;
	}
	return 0;
}

void destroy(object ob)
{
        destruct(ob);
        return;
}
// void add_hammer()
// {
//	if (this_object()->is_fighting() )
//             carry_object(__DIR__"obj/hammer")->wield();
// }
int do_sell(string arg)
{
    object ob;

        if (!arg || !(ob = present(arg, this_player())))
                return notify_fail("��Ҫ��ʲô��\n");

        if (ob->query("material") != "steel" && ob->query("material") != "iron")
                return notify_fail("������ֻ�շ�����\n");

                 else {
                message_vision("$N������һ" + ob->query("unit") +
                ob->query("name") + "��$n��\n", this_player(), this_object());
                MONEY_D->pay_player(this_player(), ob->query_weight()/70);
                        destruct(ob);
        }
	return 1;
}
int do_hit(string arg)
{
	object ob, weapon,  me = this_player();
	string file;
	if (!arg || !(ob = present(arg, this_player()))
	|| me->query_temp("marks/��") < 1)
                return notify_fail("��Ҫ��ʲô��\n");
	if (ob->query("material") != "steel" && ob->query("material") != "iron"
	|| ob->query("value") > 0) 
                return notify_fail("�㻹����һ���������ɡ�\n");
	if ( !objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "hammer")
                return notify_fail("û�к��ʵļһ�����������\n");

	if (ob->weight() < 300){
	file = resolve_path(this_object()->query("cwd"), arg);
	file = base_name(ob) + ".c";
	destruct(ob);
                ob = new(file);
	message_vision("��һ������������һ" +ob->query("unit") + ob->query("name")+
	"������������\n", me);
	command("thumb "+me->query("id"));
	command("say " +RANK_D->query_respect(me) + "������㣬����س�һλ��������");	
	message_vision("��������$N����ͭ�幤Ǯ��\n", me);
	MONEY_D->pay_player(this_player(), ob->query_weight()/100);
	destruct(ob);
	return 1;
	}

	message_vision("$N��һ" + ob->query("unit") + ob->query("name") + 
	"�ӽ���¯�պ������˳�����\n", me);
	message_vision("$NȻ��߸߾���"+ weapon->query("name") +"�Ȼ���ش���������\n", me);
	me->add("jingli", -30, "����ʱ����һ�����Լ�������");
        if ((int)me->query_skill("hammer",1) <= 100 ) {
             me->improve_skill("hammer", 1);
             write( "��Ļ������������ˡ�\n");
	     ob->set_weight(ob->weight() -10 * me->query("str"));
        if((string)weapon->query("id") == "liuxing chui") 	
	     me->improve_skill("hammer", me->query("int"));
	return 1;
	}
}

void unconcious()
{
	object obj;

	if( !query("revived") )  {
        set("eff_jing", (int)query("max_jing"));
        set("jing", (int)query("max_jing"));
        set("jingli", (int)query("max_jingli"));
        set("eff_qi", (int)query("max_qi"));
        set("qi", (int)query("max_qi"));
        set("neili", (int)query("max_neili"));	
        map_skill("strike", "luoying-shenjian");
        map_skill("dodge", "luoying-shenfa");
        prepare_skill("strike", "luoying-shenjian");
	set("revived",1);
	message_vision(HIW"$N���һ��������ͻȻ����鶯�쳣��������ʽҲ����ͬ��\n"NOR,this_object());
	
	if ( objectp(obj = this_object()->query_temp("last_damage_from"))) {
		if( present(obj->query("id"),environment(this_object())) ) {
		this_object()->fight_ob(obj);
		if( obj->query("family/family_name") == "�һ���" )
		call_out("halt_fight",5+random(10),obj);
		}
	}
	return 0;
	} else ::unconcious();
}

void halt_fight(object me)
{
	
        if (this_object()->is_fighting()) {
        	this_object()->remove_all_enemy();
		me->remove_all_enemy();
	}
	message_vision(CYN"$N������Ц������Ĭ�磬�����ù���ȫ�����һ�һ�ɣ��ѵ��㻹Ҫװ��ȥ�𣿣�\n"NOR,me);
	message_vision(CYN"$Nһ�㣬���²��ɵ��������������һԾ������սȦ�����ˡ�\n"NOR,this_object());
	message_vision(CYN"$N��̾һ�������������ҷ�Ĭ������֮�껹�ܼ����һ�ͬ�ţ���֪��ʦ�����˼ҽ����ɺã�\n",this_object());
	this_object()->set("accept_bagua",1);
}

/*
int accept_object(object me, object obj)
{
	if( !query("accept_bagua") ) return 0; 
       call_out("accept_obj", 2, me, obj);
        return 1;
}

*/

int accept_obj(object me, object obj)
{
        if( obj->query("name") == "������" ) {
	message_vision(CYN"$NĦ���������ԣ���������ӯ����\n"NOR,this_object());
	command("cry");
	command("say Ĭ�粻Ф����ʦ�����ǣ�ͬ��ǣ�ң�����"+RANK_D->query_respect(me) +"�ˡ�\n");
	me->set("help_mofeng",1);
	}
	return 1;
}
