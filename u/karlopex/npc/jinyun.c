/*-------------------------------------------------------------
** �ļ���: girl.c
** Copyright (c) 2000-2001
** ������: Lisser
** ��  ��: 2001/08/03
** ��  ��: 
**-----------------------------------------------------------*/

#include <ansi.h>
inherit NPC;
string ask_maple();
string ask_sword();
void create()
{
	set_name("˾ͽ����", ({ "situ jinyun", "situ", "jinyun", "jin", "girl" }));
	set("long", "����Ҷ������ã�����ü��Ŀ�㣬ʮ������ϲ����");
	set("title", "Ʈѩ�齣");
	set("gender", "Ů��");
	set("age", 15);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("str", 30);
	set("int", 50);
	set("con", 50);
	set("dex", 50);
	set("kar", 30);
	set("per", 30);

	set("max_qi", 10000);
	set("max_jing", 6000);
	set("neili", 8000);
	set("max_neili", 8000);
	set("jiali", 100);
	set("score", 5000);
	
	set_skill("literate", 320);
	set_skill("taoism", 400);
	set_skill("dodge", 360);
	set_skill("parry", 320);
	set_skill("sword", 400);
	set_skill("force", 360);
	set_skill("cuff", 300);
	set_skill("strike", 360);
	set_skill("taiji-quan", 300);
	set_skill("mian-zhang", 360);
	set_skill("taiji-jian", 400);
	set_skill("taiji-shengong", 360);
	set_skill("lingbo-weibu", 360);
	set_skill("qiankun-danuoyi", 360);
	
	map_skill("force", "taiji-shengong");
	map_skill("parry", "qiankun-danuoyi");
	map_skill("sword", "taiji-jian");
	map_skill("cuff", "taiji-quan");
	map_skill("strike", "mian-zhang");
	map_skill("dodge", "lingbo-weibu");

	prepare_skill("strike", "mian-zhang");
	prepare_skill("cuff", "taiji-quan");

	create_family("�䵱��", 1, "��������");
	set("combat_exp", 6400000);

/*	set("chat_chance_combat", 50);
	set("chat_msg_combat", ({
		(: auto_perform :),
	}) );
*/	
	
        set("inquiry", ([
                "Ҷ��" : (: ask_maple :),
                "����ɽׯ" : "������Ҷ��һ�ֽ����ģ�ֻ����������˶࣬����û��ʲô������",
		"��㽣" : (: ask_sword :),
		"sword" : (: ask_sword :),
        ]));

	setup();

        carry_object("/u/karlopex/obj/piaoxue")->wield();
        carry_object("/d/city/obj/pink_cloth")->wear();
}

void init()
{
	object where, ob;
	object me = this_player();
	ob = this_object();
	where = environment(ob);

	::init();

        if (interactive(me)) {
		if (environment() != load_object("/u/karlopex/workroom") ) return;
	
		if( !me || !living(ob) || strsrch(file_name(where), "/u/karlopex/") < 0
			|| environment(me) != environment() )
		return;
	
                if(getuid(me) == "buwu" || getuid(me) == "xbuwu" )
		{
			command("brother " + getuid(me));
			command("say ��ӭ������㹤�����Ӳ칤����");
			return;
			}
	
		if(getuid(me) != "karlopex" && userp(me))
		{
			if (present("karlopex", environment(me)))
			{
				message_vision(HIC"$N����$n���˸�Ҿ������λ" + RANK_D->query_respect(me)+ "����ӭ������㹤���ҡ�\n"NOR, ob, this_player());
			}else{
				message_vision(WHT"$N����$n���˸�Ҿ������λ"+RANK_D->query_respect(me)+"����ӭ������㹤���ҡ�\n$N��˵����Ҷ�����ڲ��ڼң����������ԡ�\n"NOR, ob, this_player());
			}
			if ((string)me->query("gender") == "Ů��") {
				command("sister " + getuid(me));
				command("miss " + getuid(me));
				me->set_temp("miss_situ",1);
				}
		}		
	}
        add_action("do_looko","idle");        
        add_action("do_looko","kick");
        add_action("do_looko","kick2");
        add_action("do_looko","kick3");
        add_action("do_looko","kick4");
        add_action("do_looko","kick5");
        add_action("do_looko","slap");
        add_action("do_looko","slap2");
        add_action("do_looko","slap3");            
        add_action("do_looko","cut");
	add_action("do_looko","shutup");
	add_action("do_looko","slash");
	add_action("do_looko","knife");
	add_action("do_looko","nofear");
	add_action("do_looko","points");
	add_action("do_looko","admit");
	add_action("do_looko","loveshoe");

        add_action("do_papao","slogan");
        add_action("do_papao","papaya");

        add_action("do_pato","pat");
        
	add_action("do_laugho","laugh");

	add_action("do_wao","wa");

	add_action("do_misso","miss");

	add_action("do_missb","miss2");
	add_action("do_missb","nod2");

	add_action("do_jumpo","jump");	                

	add_action("do_fearo","hug");
	add_action("do_fearo","hug2");
	add_action("do_fearo","kiss");
	add_action("do_fearo","kiss2");
	add_action("do_fearo","kiss3");
	add_action("do_fearo","kiss4");
	add_action("do_fearo","kiss5");
	add_action("do_fearo","kiss6");
	add_action("do_fearo","kiss7");
	add_action("do_fearo","kiss8");
	add_action("do_fearo","kiss9");
	add_action("do_fearo","kiss10");
	add_action("do_fearo","kiss11");
	add_action("do_fearo","mo97");
	add_action("do_fearo","lovelook");
	add_action("do_fearo","rose");
	add_action("do_fearo","deadlove");
	add_action("do_fearo","joycup");
	add_action("do_fearo","lean");
}

int do_looko(string target)
{
	call_out("do_look", 0, target);
}
int do_papao(string target)
{
	call_out("do_papa", 0, target);
}
int do_fearo(string target)
{
        call_out("do_fear", 0, target);
}
int do_pato(string target)
{
        call_out("do_pat", 0, target);
}
int do_laugho(string target)
{
        call_out("do_laugh", 0, target);
}
int do_wao(string target)
{
        call_out("do_wa", 0, target);
}
int do_jumpo(string target)
{
        call_out("do_jump", 0, target);
}
int do_misso(string target)
{
        call_out("do_miss", 0, target);
}
int do_missb(string target)
{
        call_out("do_miss2", 0, target);
}
string ask_maple()
{
	object me = this_player();
	object ob = this_object();

	if (getuid(me) == "karlopex"){
		command("sigh karlopex");
		message_vision(HIC"$N����$n˵����������û��ʧ�䣬��ô�᲻֪���Լ����£�\n"NOR, ob, me);
		return "��Ҫ����Ѱ���ģ�";
	}

	if (present("karlopex", environment(me))) return "���Լ��������ˣ�\n";

	if (!me->query_temp("ask_maple")){
		tell_object(me,"��������������ѣ���᲻֪������������ˣ�\n");
		me->set_temp("ask_maple",1);
		return "���治֪����������������ˣ�";
	}else{
		switch( random(4) ) {
			case 0:
				tell_object(me,"����һ���ܹ�ִ���ˣ��ܰ����˳��ܣ�\n");
	                        break;
	                case 1:
				tell_object(me,"����ԭ���Ժ�ǿ����������ʮ�ֵ���̲�����\n");
	                        break;
	                case 2:
				tell_object(me,"�������˺����ˣ����Ǿ������������˺������ˡ�\n");
	                        break;
	                case 3:
				tell_object(me,"˵ʵ�������������˿��ģ�����˵��˵�žͻ�����������\n");
				command("sigh");
	                        break;
			}
		me->delete_temp("ask_maple");
		return "��֮������һ���ܹŹ���ƽ����һ�������ˡ�";
		}
}
string ask_sword()
{
	object me = this_player();
	object ob = this_object();
	object new_ob;
	if (getuid(me) != "karlopex")
	{
		if (present("karlopex", environment(me))) return "������Ҫ���ˣ�\n";
		return "ΪʲôҪ���㣬��ѽ���Ҷ��ģ�����ô���������ұ��棡\n";
	}else{
		if (present("lingfeng jian", me))
		{
			command("hmm " + me->query("id"));
			return "���Ǹ������𣿻���Ҫ���ҿ�û���ˣ�\n";
		}else{
			command("ok " + me->query("id"));
			new_ob = new("/u/karlopex/obj/lingfeng");
			new_ob -> move(me);
			return "�ֶ��ˣ��治֪����ʲôʱ����ܲ���������\n";
		}
	}
}
#include "/u/karlopex/npc/jinyun_e.c"
