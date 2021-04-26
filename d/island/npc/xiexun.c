// Code of ShenZhou
//Npc: лѷ
//Date: 17/3/98, kane

#include <ansi.h>
inherit NPC;

int ask_for_dao();
int ask_for_book();

void create()
{
        set_name("лѷ", ({ "xie xun", "xie", "xun" }));
        set("long", 
"�����������Ĵ󻤽̷���֮һ�ģ���ëʨ������\n"
"����Ŀ�ΰ�쳣����ͷ�Ʒ���ɢ����ͷ���۾������͵ķ��⣬\n"
"�������ݣ����������콫һ�㡣\n");

	set("nickname", HIY"��ëʨ��"NOR);
	set("gender", "����");
	set("attitude", "heroism");

        set("inquiry",([
                "������"  : (: ask_for_dao :),
		"����ȭ"  : (: ask_for_book :),
		"qs-jing" : (: ask_for_book :),
		"����ȭ��"  : (: ask_for_book :),
		"����ȭ��"  : (: ask_for_book :),
		"����" :"����������Ѫ��������ܵ����׼���лѷ�����޺���",
		"���޼�" : "���������ѵ�֪�������޼ɺ��������䣿��",
		"����" : "�ⶼ�ǹ�ȥ�����ˣ�����������",
        ]));

	set("age", 45);
	set("shen_type", -1);

	set("str", 30);
	set("int", 25);
	set("con", 30);
	set("dex", 25);
        set_temp("apply/armor", 100);
	set_temp("apply/attack", 100);
        set_temp("apply/dodge", 100);
	set_temp("apply/damage", 50);

	set("max_qi", 3000);
	set("max_jing", 2500);
	set("neili", 2500);
	set("max_neili", 3000);
	set("jiali", 200);
	set("combat_exp", 1800000);
	set("score", 8000);
	set("PKS", 100000000);

        set_skill("force", 170);
        set_skill("hunyuan-yiqi", 170);
        set_skill("cuff", 180);
        set_skill("qishang-quan", 180);
        set_skill("blade", 170);
        set_skill("liuhe-dao", 170);
        set_skill("parry", 180);
        set_skill("dodge", 180);
        set_skill("xueshitiao", 180);
        set_skill("literate", 150);

        map_skill("force", "hunyuan-yiqi");
        map_skill("cuff", "qishang-quan");
        map_skill("blade", "liuhe-dao");
        map_skill("parry", "qishang-quan");
        map_skill("dodge", "xueshitiao");

        prepare_skill("cuff", "qishang-quan");

/*
	set("chat_chance_combat", 50);
	set("chat_msg_combat", ({
		(: auto_perform :),
	}) );
*/

	setup();

	if (clonep()) carry_object("/clone/unique/tulong-dao");
	carry_object("/d/changbai/obj/hupi")->wear();
//	carry_object(__DIR__"obj/qs-jing");
}

int ask_for_dao()
{
	object  me = this_player();
	command("shout");
	command("stare "+me->name());
	command("say "+RANK_D->query_rude(me)+"��Ȼ��֪���������������У��Թ������ɣ�\n");

        if (present("tulong dao", this_object())){
        command("wield tulong dao");
        }
        set_leader(me);
        kill_ob(me);
	return 1;
}

int ask_for_book()
{
        object  me, book;

	me = this_player();
	book = new("/clone/unique/qs-jing");
	if( !me->query_temp("xiexun_thank") ) {
        	command("grin "+me->name());
        	command("stare "+me->name());
        	command("say "+RANK_D->query_rude(me)+"��Ȼ��֪������ȭ���������У��ͳ�������ȭ�������ɣ�");
        	set_leader(me);
        	kill_ob(me);
	} 
	else if (book) {
		book->move(me);
		command("say лĳ����ѱ�������������ǣ�ң��Ȿ����ȭ���������޴��ã�"+RANK_D->query_respect(me)+"�������𣬾���ȡȥ�޷���");
		message_vision("лѷ��$Nһ��" + book->query("name") +"��\n", me);
		log_file("Xiexun",sprintf("%s(%s)�õ�����ȭ�� on %s��\n",
                me->name(), getuid(me)), ctime(time()));
	} 
	else { 
	command("say ʵ�ڶԲ�ס������ȭ���Ѿ������������ˣ�");
	}
	return 1;
}

int accept_kill(object me)
{
        command("shout");
        if (present("tulong dao", this_object())){
        command("wield tulong dao");
        }
	set_leader(me);
        kill_ob(me);
        return 1;
}

int accept_object(object me, object obj)
{      
	if((string)obj->query("name") == "������ͷ"
	&& me->query_temp("kill_chengkun") ) {
                command("ah");
		command("shout");
		command("say "+RANK_D->query_respect(me)+"�书��Ȼ������ʹлĳ����Ѫ�������������лĳ����Ϳ�أ��������ǣ�\n");
        	me->set_temp("xiexun_thank",1);
/*

	        log_file("Xiexun",sprintf("%s(%s)�ѳ�����ͷ����лѷ on %s��\n",
                me->name(), getuid(me)), ctime(time()));
*/
		return 1;
	}
	else if((string)obj->query("name") == "������ͷ"
	&& !me->query_temp("kill_chengkun") ) {	
		command("slapsb "+me->query("id"));
		command("say �Ϸ�����ä�ˣ���ȴ�ǲ�ä��");
		if (present("tulong dao", this_object())){
        	command("wield tulong dao");
        	}
        	set_leader(me);
        	kill_ob(me);	
	}

        return 0;
}
