// Code of ShenZhou
// modified by xuy 8/10/97
#include <ansi.h>

inherit NPC;
int ask_me();

void create()
{
	set_name("��������", ({ "helian tieshu", "helian", "tieshu" }) );
	set("nickname", "������ү");
	set("title", "�����󽫾�");
	set("gender", "����");
	set("age", 45);
	set("long",
		"�����������ۣ�ӥ���ǡ������롣\n");
	set("combat_exp", 50000);
        set("shen_type", -1);
	set("no_get", 1);
	set("attitude", "heroism");

	set("str", 26);
	set("con", 22);
	set("int", 20);
	set("dex", 24);

	set("max_qi", 800);
	set("eff_qi", 2000);
	set("qi", 800);
	set("max_jing", 500);
	set("jing", 500);

	set_temp("apply/attack",  60);
	set_temp("apply/defense", 60);

	set_skill("parry", 60);
	set_skill("unarmed", 60);
	set_skill("dodge", 60);
        set("inquiry",
        ([
                "Ч��" : (: ask_me :),
        ]));


	setup();

        carry_object("/d/city/obj/xiupao")->wear();
}
void init()
{
        add_action("do_kill", "kill");
}

int do_kill(string arg)
{
        object ob;
        int i;

        if (!arg || !id(arg)) return 0;

        if (present("wu shi", environment(this_object()))){
        	command("say ����ı�����٣�������������·�� ���Һ��ڣ�");
        	message_vision("�����������ҵ���ʿ��$N����������\n", this_player());

        	for(i=0; i<2; i++) {
                	if( objectp( ob = present("wu shi " + (i+1), environment(this_object())) ) )
                               	ob->kill_ob(this_player());
        	}
		this_player()->apply_condition("xakiller", 100);
	}
	return 0;
}

int ask_me()
{
	object ob, room, me=this_player();

	if(me->query_temp("try_assign_ypjob") > 0) {
		say("��������������С�ӣ���ʲô�����������ڰ�����������\n");
		command("kick " +me->query("id"));
		return 1;
	}
	
	if(!( room = find_object("/d/taishan/fengchan")) )
        room = load_object("/d/taishan/fengchan");

        if (userp(me) && me->query("id") == room->query("winner") ) {
        	command("say �������������������ÿɵ�������");
        	return 1;
        }

	if ((int)me->query_condition("ypjob") > 0) {
		say("����������ŭ��������ģ������Ļû��ɣ���Ȼ�����������ң�\n");
		command("slap " +me->query("id"));
		return 1;
	}

	if ( ((int)me->query("yipin/done")+30)/
			((int)me->query("yipin/failure")+1) < random(3)) {
		command("sneer " +me->query("id"));
		say("����������Ц��������Ъ����ɣ�����ͷ�⼸׮���¿��Ų�������ȥ����\n");
		me->delete_temp("xixia/testpass");
		me->delete_temp("xixia/һƷ��");
		me->delete_temp("apply/short");
		me->apply_condition("ypjob", 100);
		return 1;
	}
 
	if (me->query_temp("xixia/һƷ��")) {
		command("nod " +me->query("id"));
		me->set_temp("try_assign_ypjob", 1);
		if (me->query_condition("xakiller") > 0)
		me->apply_condition("xakiller", 0);
		call_out("assign_job", 1, me, 1);
		return 1;
	}

	if ((int)me->query_temp("xixia/testpass")) {
		say("��������������Ц�����ã������������������һƷ�������°ɣ�\n");
		me->set_temp("xixia/һƷ��",1);
		me->delete_temp("xixia/testpass");
		me->set_temp("apply/short",
     ({ HIW"����һƷ����ʿ "NOR+me->query("name")+"("+capitalize(me->query("id"))+")"}));
		me->set_temp("try_assign_ypjob", 1);
		if (me->query_condition("xakiller") > 0)
		me->apply_condition("xakiller", 0);
		call_out("assign_job", 1, me, 1);
		return 1;
	} else {
		return notify_fail ("��������˵������ȥ��Ŭ�����ɡ�\n");
	}
}

private int is_suitable(object victim, object killer)
{
	string *no_kill_list = ({
		"mu ren",
		"mengzhu",
		"shangshan shizhe",
		"fae shizhe",
		"xuantong dashi",
		"feng qingyang",
		"huang zhen",
		"juexin dashi",
		"yideng dashi",
		"ren woxing"
	});

	if( victim->query("combat_exp") < killer->query("combat_exp")
	 || victim->query("combat_exp") > killer->query("combat_exp")*7/4
	 || !clonep(victim) || userp(victim) 
	 || victim->query("race") != "����"
	 || victim->query("shen") < 0
	 || victim->query("winner")
	 || strsrch(base_name(victim), "/kunfu/skill") == 0
	 || strsrch(base_name(victim), "/d/xiakedao/") == 0
	 || strsrch(base_name(victim), "/d/beijing/") == 0
	 || strsrch(base_name(victim), "/clone/user") == 0
	 || strsrch(base_name(victim), "/u/") == 0
	 || member_array(victim->query("id"), no_kill_list) != -1 ) 
	{
		return 0;
	} 
	return 1;
}

void assign_job(object me, int try_times)
{
	object ob, *victim_list;
	int i;
	string str, ttt;
	
	victim_list = filter_array(livings(), "is_suitable", this_object(), me);
	if( sizeof(victim_list) == 0 ) {
	// try again in 5 secs.
		if( try_times > 5) {
			say("��������˵����" + me->query("name") + "��ʵ�����Ҳ����ʺ���ɱ���ˣ��´������ɡ�\n");
			me->delete_temp("try_assign_ypjob");
		}
		else {
			say("��������˵����" + me->query("name") + "����ʱ�Ҳ����ʺ���ɱ���ˣ���5�뿴����\n");
			call_out("assign_job", 5, me, try_times+1);
		}
		return;
	}

	me->apply_condition("ypjob", 70);
	me->delete_temp("try_assign_ypjob");
	i = random(sizeof(victim_list));

	ttt=gender_pronoun(victim_list[i]->query("gender"));

	say("��������˵����"+victim_list[i]->query("name")+"����һֱ���������Ĺ����ԣ�"
	    +"��ȥ���Ұ�"+ttt+"ɱ�ˣ�\n");
	tell_object(me,"��������˵���Ӹ���һ�������\n");
	ob=new(__DIR__"obj/ypling");
	ob->set("long", "����һ������һƷ�����������д�š�"+victim_list[i]->query("name")+"����\n");
	ob->set("victim", victim_list[i]->query("name"));
	ob->set("owner", me->query("id"));
        ob->move(me);
}

int accept_object(object who, object ob)
{
	string *award_list = ({
	"����",
	"�ɽ�",
	"�ɶ�",
	"���߹�",
	"��ҩʦ",
	"������",
	"������"
	});

	int gain;

	if (ob->query("id") != "head" 
	 || ob->query("owner") != who->query("id"))
		return 0;

	if (who->query_temp("xixia/һƷ��")){
	gain = ob->query("gain");
		if (who->query_condition("ypjob") > 0 && ob->query("gain")){
		who->add("combat_exp", gain * 6 + random(gain*5));
		who->add("potential", gain * 3 + random(gain));
		if (who->query("potential") > who->query("max_potential"))
			who->set("potential", who->query("max_potential"));
		command("u&me "+who->query("id"));
		command("say ƾ������ȥŬ���������칤Ǯ�ɡ�");
		who->add("yipin/done", 1);
		who->apply_condition("ypjob", 0);

	if (member_array(ob->query("victim_name"), award_list) >= 0  
	&& ob->query("combat_exp") > who->query("combat_exp")*3/2)
		who->add("combat_exp", gain*30);		
	}
	else {
		command("kick "+who->query("id"));
		say("����������ŭ����û�õĶ������������Ÿ������㻹�����������ң�\n");
		who->add("yipin/failure", 1);
	}		
	call_out("destroy_it", 1, ob);
        return 1;
	}
}

void destroy_it(object ob)
{
        destruct(ob);
        return;
}

void unconcious()
{
        message_vision("\nͻȻ��$Nһ�������ϵĻ��أ�ֻ��ǽ���ֳ�һ���Ŷ���$Nת�����˽�ȥ��\n",
                this_object());
        destruct(this_object());
}	
