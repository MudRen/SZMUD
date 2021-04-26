// yangguo.c ���
// By Xuanyuan 2001-9-5 

#include <ansi.h>
inherit NPC;
inherit F_MASTER;
int des_object()
{
	message_vision( "ȴ����$N����˵��������������˲�ǳ�����ս�����꣬�ٵ������Ի������Ǿʹ˱������˵������һ����ƮȻ��ɽ��\n", this_object() );
        destruct(this_object());
        return 1;
}
int ask_strike();
int ask_youju();

void create()
{
	set_name("���", ({ "yang guo", "yang" }));
	set("title", "������");
	set("gender", "����");
	set("age", 32);
	set("per",30);
	set("con",30);
	set("int",30);
	set("str", 30);
	set("dex", 30);
	set("class","swordman");
	set("long", "����һλ�ߴ�����ӣ���ò���㡣\n"+
	"һֻ����տ���Ҳ�����Ƕ���һ�ۣ�������ˣ�\n"+
	"��Ȼ�ڲ�ס�����˵ķ�ɡ�\n");
	set("combat_exp", 3500000);
	set("score", 10000);
	set("shen_type", 1);
	set("attitude", "peaceful");
	set("neili", 8000); 
	set("max_neili", 8000);

	set_skill("force", 400);
	set_skill("strike", 400);
	set_skill("dodge", 380);
	set_skill("parry", 380);
	set_skill("literate", 100);
	set_skill("xiaohun-zhang",400);
	set_skill("yunu-xinjing", 400);
	set_skill("gumu-shenfa",380);
	set_skill("yunu-jue", 300);
	map_skill("parry", "xiaohun-zhang");
	map_skill("strike","xiaohun-zhang");
	map_skill("dodge", "gumu-shenfa");
	map_skill("force", "yunu-xinjing");
        prepare_skill("strike", "xiaohun-zhang");

	set("chat_chance_combat", 80);
	set("chat_msg_combat", ({
                (: perform_action, "parry.xiaohun" :),
                
        }) );
	set_temp("apply/attack", 100);
	set_temp("apply/damage", 100);
	set_temp("apply/defense", 100);
	set_temp("apply/armor", 100);

        set("inquiry", ([
                "С��Ů" : "She is my wife��\n",
		"��Ȼ������" : (: ask_strike :),
		"��Ĺ�ľ�" : (: ask_youju :),
       ]) );
	create_family("��Ĺ��", 3, "����");
	setup();
	carry_object("/clone/misc/cloth")->wear();
	add_money("gold", 2);
}
void init()
{
        ::init();
        add_action("do_yuanyi","yuanyi");
}
void attempt_apprentice(object ob)
{
        command("say �Ҳ��յ��ӣ���λ"+RANK_D->query_respect(ob)+"������ذɡ�");
	return;
}

int accept_kill(object obj)
{
        object ob = this_player();
	command("chat* oh " + obj->query("id") + "" );
	command("chat ԭ�������ϻ���" + ob->name() + "��Ȳ�������"+RANK_D->query_respect(ob)+"��");
	return 1;
}
void die()
{
	object ob, me;
	me = this_object();

	if( !living(this_object()) ) revive(1);
	command("chat* disapp");
	if( objectp(ob = me->query_temp("last_damage_from")) )
	{
		command("chat " + ob->name() + "������أ��������Ž��ޱȡ�");
		command("chat* admire2 yang guo");
	}
	::die();
}
int ask_strike()
{
        object ob = this_player();
	int my_strike, add_level;
	my_strike = ob->query_skill("xiaohun-zhang", 1);

	if ( ob->query("yangguo_taught") ) {
		command( "say ���ܽ�����Ѿ����ˣ��պ�ֻ�п����Լ��������������Ȼ������⾳��\n");
		des_object();
		return 1;
	}
        if ( ob->query("family/family_name") != "��Ĺ��" ) {
                command("say �������ں���֮�п����������һʮ�����Ʒ���");
		des_object();
                return 1;
        }
	if ( ob->query("gender") != "����" ) {
                command("say �������ں���֮�п����������һʮ�����Ʒ���");
                command("say �����Ʒ��ұ����Դ������㣬������Ҫ���������Ը���Ϊ������Ů���ǲ�����ϰ�ġ�");
                command("sigh2");
		des_object();
                return 1;
        }

	command("say "+RANK_D->query_respect(ob)+"��Ȼһ�����������ҿ�ν��Ե������ָ����һЩ�书�ɡ�");
	message_vision( "�����ʼΪ$N��˵��Ȼ�����Ƶľ��塣\n", ob );
	tell_object( ob, "�����Ȼ�����������˶�ʮ����\n");
        command("say �����Ʒ�����Ϊ����Ȼ�����ơ���ȡ���ǽ��͡��𸳡����Ǿ䡰��Ȼ�����ߣ�Ψ������ӡ�֮�⡣");
        command("say ������������仰�����ʱ�����������������ܿ�ɽҲ����ʯ��");
	add_level = my_strike + 20;
	ob->set_skill("xiaohun-zhang", add_level);
	ob->set("yangguo_taught", 1);
	ob->add("combat_exp", 15000);
	des_object();
	return 1;
}

int ask_youju()
{
        object ob = this_player();
        
        if (ob->query("family/family_name") != "��Ĺ��") {
                command("say ���ǡ���Ůȭ�������һ�е���ʽ���������Դ��ġ�");
		des_object();
                return 1;
        }
	if (ob->query("family/master_name") == "��Ī��") {
                command("say ���ǡ���Ůȭ�������һ�е���ʽ���������Դ��ġ�");
                command("say ������ʦ����Ī��ĵ��ӣ��ұ�����ָ�����㡣");
                command("say ��Ȼһ�������������Ը������Ϊ��ȥ�����ϵ�а����ָ�������С���Ĺ�ľӡ�����Ը��(yuanyi)��");
        	ob->set_temp("mark/youju", 1);
		return 1;
		}     
        if (ob->query("gumu/youju") > 0 ) {
                command("say �㲻���Ѿ�ѧ������");
		des_object();
                return 1;
        }
        if ((int)ob->query_skill("cuff", 1) < 120) {
                command("say Ҫʹ�������ľ�����Ҫ�����ȭ�����㻹�Ƕ���ϰ��ϰ����Ůȭ������˵�ɡ�");
		des_object();
                return 1;
        }
	command("say ���ǡ���Ůȭ�������һ�е���ʽ���������Դ��ġ�");
	command("say �ã���Ȼһ�����������ҿ�ν��Ե������ָ�������С���Ĺ�ľӡ���");
	message_vision( "$N��ϸ��$n�����ˡ���Ĺ�ľӡ��ľ�Ҫ���ڡ�\n",this_object(), ob );
        ob->set("gumu/youju", 1);
	des_object();
        return 1;
}

int do_yuanyi()
{
        object me=this_player();

        if (!me->query_temp("mark/youju"))
                return 0;
      
	message_vision("$n������$N���ϼ������Ŵ�Ѩ�������¡�\n", me, this_object() );
        write("��е�ͷ����һ��̩ͨ��\n");
        me->set("shen", 0);
	command("say �ã����ӿɽ̣��Ҿ�ָ�������С���Ĺ�ľӡ���");
	message_vision( "$N��ϸ��$n�����ˡ���Ĺ�ľӡ��ľ�Ҫ���ڡ�\n",this_object(), me );
        me->delete_temp("mark/youju", 1);
        me->set("gumu/youju", 1);
	des_object();
        return 1;
}
