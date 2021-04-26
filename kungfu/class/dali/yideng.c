// Code of ShenZhou
inherit NPC;
#include <ansi.h>
#include "/kungfu/class/dali/auto_perform.h"

string ask_me(object);
int do_answer(string);

void create()
{
	set_name("һ�ƴ�ʦ", ({ "yideng dashi", "yideng", "dashi" }));
	set("nickname", "�ϵ�");
	set("long", "�������θߴ����������İ�ü���۽Ǵ�����������Ŀ���飬ü\n����������࣬��һ��Ӻ�ݸ߻�����ɫ��ȴ��һ����֪��\n");
	set("gender", "����");
	set("age", 55);
	set("attitude", "heroism");
	set("shen_type", 1);
	set("str", 30);
	set("int", 50);
	set("con", 30);
	set("dex", 30);
	set("max_qi", 4000);
	set("max_jing",4000);
	set("neili", 5000);
	set("max_neili", 5000);
	set("jiali", 200);
	set("combat_exp", 3600000);

	set_skill("force", 400);
	set_skill("dodge", 400);
	set_skill("parry", 400);
	set_skill("finger", 400);
	set_skill("kurong-changong", 400);
	set_skill("yiyang-zhi", 400);
	set_skill("cuff", 400);
	set_skill("strike", 400);
	set_skill("buddhism", 400);
	set_skill("sword", 400);
	set_skill("duanshi-shenfa", 400);
	set_skill("duanjia-jian", 400);
	set_skill("qingyan-zhang", 400);
	set_skill("jinyu-quan", 400);
	set_skill("medicine", 300);
	
	map_skill("dodge","duanshi-shenfa");
	map_skill("cuff", "jinyu-quan");
	map_skill("strike","qingyan-zhang");
	map_skill("force", "kurong-changong");
	map_skill("sword","duanjia-jian");
	map_skill("parry", "yiyang-zhi");
	map_skill("finger", "yiyang-zhi");
	prepare_skill("finger", "yiyang-zhi");
	prepare_skill("strike", "qingyan-zhang");

	set("chat_chance_combat", 50);
	set("chat_msg_combat", ({
	        (: auto_perform :),
	}) );

	set("inquiry", ([
	        "name" : "ƶɮ����һ�ơ�\n",
	        "here" : "������ƶɮ���ӵĵط��������뿴��ɽ��ˮ�㣬�ø�����֮������\n",
	        "����" : (: ask_me :),
	        "����" : (: ask_me :),
	]) );

	create_family("����μ�", 14, "����");
	setup();
	carry_object("/d/shaolin/npc/obj/cloth")->wear();
//	carry_object("/clone/weapon/changjian")->wield();
}

void init()
{
	object ob,who=this_player(),me=this_object();
	if (interactive(ob=this_player())
		&& ob->query("family/master_id") == "yideng dashi"
		&& ob->query("shen") < 0 )
	{
		command("look "+getuid(ob));
		command("sigh");
		command("say "+RANK_D->query_respect(ob)+"�㼴��������ȴ���Ĵ������������޷���...��...ȥ�ɣ�");
		command("expell "+ob->query("id"));
	}
	if(interactive(ob=this_player())
		&& ob->query("gender") == "����" 
		&& ob->query("family/master_id") == "yideng dashi")
	{
		command("look "+getuid(ob));
		command("sigh");
		command("say "+RANK_D->query_respect(ob)+"����������ȴ��Ͷ�붫�����£�Ϊʦ�޷������㣬��...��...ȥ�ɣ�");
		command("expell " + ob->query("id"));
	}
	/* 
	if (!userp(who)
		&& ob->query("family/family_name") != "����μ�"
		&& environment()==find_object("/d/dali/yideng12.c"))
	{
		message_vision("$N��$n�ȵ���������˭������ô�����������ģ���\n",me,who);
		message_vision("$N˫�ƺ�ʮ�����������գ����գ��ҷ�ȱ���Ҳ��ʨ�Ӻ�������������һ�̰ɡ���\n",me);
		kill_ob(who);
	}
	*/

	  add_action("do_answer","answer");
}

void attempt_apprentice(object ob)
{
	if (ob->query("family/family_name")!="����μ�")
	{
		command("say "+RANK_D->query_respect(this_player())+"�Ǳ��ɵĸ��֣������Ƨ֮�粻�Ҷ�����");
		return;
	}

	if (ob->query("shen")<0)
	{
		command("say ���գ����գ���λʩ���������֮ɫ�����ķ𷨵�ǳ�����ǻ��ⲻ�ˡ�");
		return;
	}

	if (ob->query_skill("kurong-changong", 1)<80)
	{
		command("say "+RANK_D->query_respect(this_player())+"����ڹ���δ�������ң���������������ȥ�ɡ�");
		return;
	}

	if (ob->query_skill("finger", 1)<80)
	{
		command("say "+RANK_D->query_respect(this_player())+"ָ��������������᲻���ҵ�һ��ָ����������������ȥ�ɡ�");
		return;
	}

	if (ob->query_skill("yiyang-zhi", 1)<50)
	{
		command("say "+RANK_D->query_respect(this_player())+"ָ��������������᲻���ҵ�һ��ָ����������������ȥ�ɡ�");
		return;
	}

	if (ob->query_str()<25)
	{
		command("say "+RANK_D->query_respect(this_player())+"���۷�����������������ϳ��书��");
		return;
	}

	if (ob->query_int()<32)
	{
		command("say "+RANK_D->query_respect(this_player())+"������³��������������ϳ��书��");
		return;
	}

	if (ob->query_con()<26) {
		command("say "+RANK_D->query_respect(this_player())+"����̫����������������ϳ��书��");
		return;
	}

	if (ob->query_dex()<26) {
		command ("say "+RANK_D->query_respect(this_player())+"��Ϊϰ��֮��ȴ��˴��֣������������㡣");
		return;
	}

    command("say �ðɣ��Ҿ��������ˡ���Ը���Ĵ�����������");
	ob->set_temp("title", ob->query("title"));
	command("recruit " + ob->query("id"));
	ob->set("title", ob->query_temp("title"));
	ob->delete_temp("title");
	return;
}

string ask_me(object who)
{
	object me;
	me=this_player();

	if (environment(me)!=find_object("/d/dali/yideng12.c"))
		return "ʩ���ʵ���ʲô��ƶɮ��֪������\n";
	if (me->query_temp("yideng_asked"))
		return "����Ҫ������\n";
	else {
		if (me->query("family/master_id")=="yideng dashi")
		{
			me->set_temp("yideng_asked",1);
			return "��ͽ������Ϊʦ����Ȼ������Ϊ�����ƣ�����֪ͽ�����Ƿ���Ҫ��\n";
		}
		else {
			me->set_temp("yideng_asked",1);
			return "ʩ����Ȼ��Ե�������£�ƶɮ�������񾡵���֮��Ϊ�������ƣ���֪�����Ƿ���Ҫ��\n";
		}
	}
}

void do_answer(string arg)
{
	object me;
	me=this_player();

	if (arg=="��Ҫ����" && me->query_temp("yideng_asked"))
	{
		tell_object(me, "������һ�ƴ�ʦΪ���˹����ơ�\n");
		me->delete_temp("yideng_asked");
		if (me->query("dali/yideng_rewarded"))
		{
			command("look "+getuid(me));
			command("say ����������һ�Σ����Ѿ��þ���Ե�ˣ���������");
			command("say Ϊ�����̰�����ᣬ���������뿪����ɡ�");
			message_vision("$N�����ѵ�����ɫͨ�죬��������뿪�ˡ�\n", me);
			me->move("/d/dali/maze1");
			return;
		}
		if (me->query("family/master_id")=="yideng dashi")
		{
			command("pat "+getuid(me));
			command("smile");
			command("say �õģ�Ϊʦ��͸������ơ������ҵ���������");
			me->set_temp("yideng_waitreward",1);
			me->delete_temp("yideng_asked");
			this_object()->move("/d/dali/yideng10.c");
			me->move("/d/dali/yideng10.c");
			command("say ��׼�����˾͸����ҡ�");
			return;
		}
		if (me->query("kar")>random(30))
		{
			command("look "+getuid(me));
			command("smile");
			command("say �õģ�������͸������ơ������ҵ���������");
			me->set_temp("yideng_waitreward",1);
			me->delete_temp("yideng_asked");
			this_object()->move("/d/dali/yideng10.c");
			me->move("/d/dali/yideng10.c");
			command("say ��׼�����˾͸����ҡ�");
			return;
		}
		else {
			command("look "+getuid(me));
			command("sigh");
			command("say ʵ�ڱ�Ǹ��ʩ����Ե�ֲ��������Ĳ���Ϊ�����ơ�");
			command(":(");
			me->delete_temp("yideng_asked");
			me->set("dali/yideng_rewarded",1);
			return;
		}
	}
	if (arg=="��׼������"
		&& me->query_temp("yideng_waitreward")
		&& environment(me)==find_object("/d/dali/yideng10.c"))
	{
		command("nod");
		command("say ������������Ϳ�ʼΪ�������ˡ�");
		write("һ�Ƶ�����Ŀ��ü���붨�˹�������Ծ���������أ�������� \n");
		write("ʳָ������������ͷ���ٻ�Ѩ��ȥ�������ɼ���΢΢һ����\n");
		write("ֻ����һ�������Ӷ���ֱ͸������\n");
		write("һ��һָ������������أ��ڶ�ָ���������İٻ�Ѩ��һ����\n");
		write("�ִ��ĺ�Ѩ������ǿ�䣬�Ի����縮����׶���յ���������\n");
		write("�������̨һ·�㽫������һ֧��ȼ��һ�룬�ѽ��㶽������ʮ \n");
		write("��Ѩ˳�ε㵽��\n");
		message_vision(HIR "$NͻȻ����һ��ů���Զ����룬��ǰһ�ھ�ʲôҲ�������ˣ�\n" NOR, me );
		me->unconcious();
		
	if (me->query("family/master_id")=="yideng dashi")
	{
		me->set("con", me->query("con")+2);
		me->set("dex", me->query("dex")+1);
		me->set("str", me->query("str")+1);
               log_file("static/AddGift", sprintf("[%s]   %s   %s(%s)��һ�ƴ�ʦ�������%s�������%s����ǡ�%s������\n", 
                        ctime(time())[0..15], me->query("family/family_name"),me->name(), geteuid(me),"��","һ","һ")); 
        me->add("AddGift/dl/str", 2);  
        me->add("AddGift/dl/dex", 1);  
        me->add("AddGift/dl/con", 1);  
	}
		me->add("max_neili",150);
		me->add("combat_exp",15000);
		me->set("dali/yideng_rewarded",1);
		me->delete_temp("yideng_waitreward");
		this_object()->move("/d/dali/yideng12.c");
		me->move("/d/dali/yideng12.c");
		return;
	}
	return;
}
