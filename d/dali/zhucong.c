// Code of ShenZhou
// zhucong.c   �����߹� ���

#include <ansi.h>

inherit NPC;

int improve_gbskill(string arg);
int do_steal(string);

void create()
{
	set_name("���", ({"zhu cong", "zhu"}));
	set("title", "�����߹�  �϶�");
	set("nickname", "��������");
	set("gender", "����");
	set("age", 35);
	set("long", "
һ�����������ʿ�ˣ�����˹�ĵ�����������ȴ����ЬƤ��������
��ֱ�죬һ·��һ·���Ź�Ƿ��������Ц��Ц����üŪ�ۣ�һ������
������ȫ�����壬�¹ڲ����������۹���������˵Ҳ��ʮ����ûϴ��
�ˣ�����һ�����õ���ֽ���ȣ���ҡ���С�\n");
	
	set("attitude", "peaceful");
	
	set("str", 25);
	set("int", 25);
	set("con", 30);
	set("dex", 30);

	set("chat_chance", 3);
	set("chat_msg", ({
		"���ҡͷ���Ե�������������֮�ơ�����������������ʴ�ۡ�����Ƣ������\n",
	}));

	set("inquiry", ([
		"�����߹�" : "�Ҿ����߹�����϶�������������ʲô�¶���\n",
	]));


	set("qi", 800);
	set("max_qi", 800);
	set("jing", 2000);
	set("max_jing", 2000);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 60);
	
	set("combat_exp", 200000);
	 
	set_skill("force", 80);
	set_skill("huntian-qigong", 80);
	set_skill("hand", 100);
	set_skill("shexing-diaoshou", 100);
	set_skill("dodge", 100);
	set_skill("xiaoyaoyou", 100);
	set_skill("parry", 80);
	set_skill("stealing", 200);  
	
	map_skill("force", "huntian-qigong");
	map_skill("hand",  "shexing-diaoshou");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("parry", "shexing-diaoshou");

	setup();
	
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
	set_heart_beat(1);

	add_action("do_steal", "steal");
}

int do_steal(string arg)
{
	object me=this_object(), who=this_player();
	string a,b,c;
	if (!arg || sscanf(arg, "%s %s %s", a, b, c) != 3 ) return 0;
	if ( !who->query_temp("stealing") && b=="from" && (c=="zhu cong" || c=="zhu")) {
        tell_object(who, "�㲻����ɫ������������ϣ��ȴ��������� ...\n\n");
		who->set_temp("stealing",1);
		remove_call_out("stealzhu");
		call_out("stealzhu",3, me,who);
		return 1;
	}
	return 0;
}

int stealzhu(object me, object who)
{
	who->delete_temp("stealing",1);
	if (present(who,environment(me))) {
		who->add_temp("stealzhu", 1);
		if (who->query_temp("stealzhu")>5) {
			if (who->query("kar")>(10+random(15)) && random(4)!=0) {
				command("hehehe "+who->query("id"));
				command("say "+RANK_D->query_rude(who)+"͵���ô�أ������ӵ�������ͬ�����������ǽ������ѣ���������͵���ɡ�");
				command("hehe zhu cong");
				who->add("jn7g/jiaoqing",1);
				who->delete_temp("stealzhu");
				return 1;
			}
			else {
				command("killair "+who->query("id"));
				command("say �ϻ���������"+RANK_D->query_rude(who)+"����ҵ���è��");
				who->delete_temp("stealzhu");
				me->kill_ob(who);
				return 1;
			}
		}
		if (who->query_temp("stealzhu")>2) {
			message_vision("$Nһ��ͷ��һ��׽ס��$n���֣�������Ц������"+RANK_D->query_rude(who)+"������͵����ʦүͷ�����ˣ������İɡ�\n",me,who);
			command("killair "+who->query("id"));
			message_vision("$Nŭ�����ض�$n˵������"+RANK_D->query_rude(who)+"һ���٣��ٶ����ظ����ӵ��ң�����һ�����ӾͲ������ˣ�\n",me,who);
		}
	}
	return 1;
}