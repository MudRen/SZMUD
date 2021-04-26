// Code of ShenZhou
//zhanbu ��npc ��ʿ by maco
inherit NPC;
#include <ansi.h>
#include "/d/REGIONS.h";

void create()
{
        set_name("��ʿ", ({ "xiang shi", "shi" }));
        set("long","һ����̯�����ĵ�ʿ����ɫٲȻ�����������е����Ī�⡣\n");
        set("gender", "����");	
	set("age", 40);
	set("attitude", "friendly");
	
	set("max_qi", 400);
	set("max_jing", 400);
	set("neili", 50);
	set("max_neili", 50);
	set("combat_exp", 10000);

	set_skill("force", 30);
	set_skill("dodge", 30);
	set_skill("parry", 30);
	set_skill("qimen-dunjia", 60);


        set("inquiry", ([
		"ռ��" : "����ƶ��������������΢������÷���������������㡢�������࣬ƶ��������ͨ����Ҫʮ���ƽ�ƶ����������ֱ�ϣ�ǧ��һʧ��������ȻǮ������׼....",
        ]));

	setup();
	carry_object("/d/wudang/obj/greyrobe")->wear();
}

void init()
{
        ::init();
	add_action("do_divine", "divine");
	add_action("do_divine", "zhanbu");
}

int do_divine(string arg)
{
        object ob, where, env, me = this_player();
        string region;
	
	if (!me->query_temp("zhanbu_gold"))
		return 0;

        if( !living(this_object()) )
                return notify_fail("��....����Ȱ���ʿŪ����˵��\n");

        if( this_object()->is_busy() )
                return notify_fail("��ʿ˵�������Եȣ�����æ���š�\n");

	if(this_object()->query("jing") < 80)
                return notify_fail("��ʿ˵�������Եȣ������ں��ۡ�\n");

	if (!arg) return notify_fail("��ʿ�����㣺��Ҫռ��˭��λ�ã�\n");
	
        if( !(ob = find_player(arg)) )
        if( !(ob = find_living(arg)) )
	        return notify_fail("��ʿ�����㣺����û����ˡ�\n");
	if ( arg == "mariner" ) return notify_fail("��ʿ�����㣺����û����ˡ�\n");
        if( ob == me )
	        return notify_fail("ռ���Լ���λ�ã�û�����Ҫ�ɡ�\n");
	        
        if( ob == this_object() )
	        return notify_fail("Ҫ��ʿռ���Լ����˷�ǮҲ���������ӡ�\n");

	write("\n������ʿ�Ķ�������˵�����鷳��������ռ��"+ob->name()+"�����ڡ�\n\n");
        tell_room( environment(me), "\n"+me->name() + "����ʿ����С����˵��Щ����\n", ({ me, this_object() }) );

	message_vision(CYN"��ʿ����һֻľ���������������Ĵָ�������������ӡ���������î�������ȡ��硢δ���ꡢ�ϡ��硢��\n������λ��ϸ��������������\n\n"NOR, me);
	me->start_busy(1);

	if( !(where = environment(ob)) ) {
		command("doubt xiang shi");
	        return notify_fail("��ʿ�����㣺����ˡ���Ŀǰ�Ҳ�����\n");
		}
        if( !wizardp(me) && wizardp(ob) ) {
		command("fear");
		return notify_fail("��ʿ��ɫ���ף������������������ʦ���ҿɲ���˵��\n");
		}
        if( strsrch(file_name(where), "/d/") != 0
        ||  undefinedp(region = region_names[explode(file_name(where), "/")[1]]) ) {
        	command("doubt xiang shi");
                return notify_fail("��ʿ�����㣺����ˡ���Ŀǰ�Ҳ�����\n");
		}

	env = environment(me);

	if( random(me->query_kar()/2) + me->query_temp("zhanbu_gold") > ob->query_kar()*3/2 ) {
	
	command("whisper "+me->query("id")+" "+ob->name()+"("+ob->query("id")+")������"+region+""+where->query("short")+"��");
		if( random(me->query("kar")) < ob->query("kar") )
		tell_object(ob, HIB"��о����񲻶����ƺ������ڰ��п�������......������"+me->query("name")+"("+me->query("id")+")��\n"NOR);
	} 
	
	else if( me->query_kar() + me->query_temp("zhanbu_gold") > random(ob->query_kar()) ) {
	command("whisper "+me->query("id")+" "+ob->name()+"("+ob->query("id")+")������"+region+"һ����");
	 	if( random(me->query("kar")) < ob->query("kar"))
                tell_object(ob, HIB"��о����񲻶����ƺ������ڰ��п�������......������"+me->query("name")+"("+me->query("id")+")��\n"NOR);

	} else {
	command("dunno");
	command("say "+ RANK_D->query_respect(me) +"���Ľ���̫....��������Ե̫�����ƶ���е��㲻�����.....");
	}
	
	me->delete_temp("zhanbu_gold");
	add("zhanbu_times",1);

	if(query("zhanbu_times") > 8){
	command("rich xiang shi");
	command("say ���칻���ˣ���̯��");
        message_vision("$N�첽�뿪�ˡ�\n",this_object());
        destruct(this_object());

	}
	
	return 1;
}


int accept_object(object who, object ob)
{
        object me = this_player();
        if(me->query("combat_exp") < 10000)
                return notify_fail("��ľ���̫���ˣ��޷�����ռ����\n");

        if (ob->query("money_id") && (int)me->query_skill("qimen-dunjia",1) > 60 && me->query("family/family_name") == "�һ���"){
                tell_object(who, "��ʿ����������"+ RANK_D->query_respect(me) +"�Լ��������Ŷݼ׵ĺ��֣��ͱ������ҳ��ӣ���ƶ����ڷ��԰ɣ�\n");
                return 0;
                }

        if (ob->query("money_id") && ob->value() >= 100000 ) 
        {
        
                who->add_temp("zhanbu_gold",ob->value()/100000);
		command("rich xiang shi");
		command("say "+ RANK_D->query_respect(me) +"Ҫռ��(zhanbu)Щʲ�᣿");
                return 1;
        }
        else if (ob->query("money_id") && ob->value() < 100000) 
        {
	message_vision("��ʿ˫��һ��������ʮ���ƽ��ǻ�Ҫ�����᣿\n", me);
                return 1;
        }

        return 0;
}
