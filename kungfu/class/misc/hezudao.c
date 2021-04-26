// Code of ShenZhou
// �������npc�� (����û��������)  by maco

inherit NPC;
#include <ansi.h>

int ask_score();
string ask_win();
string ask_lose();

void create()
{
        set_name("�����", ({ "he zudao", "he", "zudao" }));
        set("nickname", "������ʥ");
        set("long", "����һ���������µ��������ӣ�������Ŀ���ݹ����⣬\n"
        "�����١����������������ơ�������ʥ����\n"
        "Ŀǰ���ݵ�������Է��������Ҳ��¼���������������ʿ�ɼ���\n");
        set("gender", "����");
        set("age", 36);
        set("special_npc", 1);
        set("no_get", 1);
	set("title", "���������š���Է����");
        set("attitude", "heroism");
        set("str", 30);
        set("int", 33);
        set("con", 29);
        set("dex", 33);
        set("max_qi", 6000);
        set("max_jing",6000);
        set("neili", 5000);
        set("max_neili", 5000);
        set("jingli", 3000);
        set("max_jingli", 3000);
        set("jiali", 250);
        set("combat_exp", 3600000);


        set_skill("force", 360);
        set_skill("dodge", 400);
        set_skill("parry", 360);
        set_skill("strike", 360);
        set_skill("sword", 400);
        set_skill("literate", 300);
        set_skill("qimen-dunjia", 280);
        set_skill("taixuan-gong", 360);
        set_skill("liangyi-jian", 400);
        set_skill("poem-dodge", 360);
        set_skill("liuyang-zhang", 360);
        
        map_skill("dodge","poem-dodge");
        map_skill("strike","liuyang-zhang");
        map_skill("sword", "liangyi-jian");
        map_skill("force", "taixuan-gong");
        map_skill("parry", "liangyi-jian");
        prepare_skill("strike", "liuyang-zhang");

	create_family("������", 1, "����");

        set("inquiry", ([
                "name" : "���պΣ����ֽ������������\n",
                "������ʥ" : "�������򴳳���һ��СС��ͷ�����ص�����˵���ٽ�������������˵��������ʥ����ʥ����ʥ�����ҳ���ס������ɽ�У����Ը�����һ����ţ�������������ʥ����\n",
                "������ʥ�����" : "�����ʥ���֣��������׳Ƶõģ���Ȼ���˸�����������Ҳ�����ԾӲ��ɣ�������Ҹ����Լ������֣��������������������˵�����ǡ�������ʥ����������˼����ˣ��㲻��˵�ҿ����Դ��ˡ�\n",
		"�����" : "�����ʥ���֣��������׳Ƶõģ���Ȼ���˸�����������Ҳ�����ԾӲ��ɣ�������Ҹ����Լ������֣��������������������˵�����ǡ�������ʥ����������˼����ˣ��㲻��˵�ҿ����Դ��ˡ�\n",
               	"�ɼ�" : (: ask_score :),
		"score" : (: ask_score :),
		"����" : "�������ָ���help c_chess�С�\n",
		"Χ��" : "�����ݡ���δ����Χ�塣\n",
		"����" : "�����Լ��ĳɼ������㿪ʼ������clean��",
		"abandon" : "�����Լ��ĳɼ������㿪ʼ������clean��",
		"clean" : "�����Լ��ĳɼ������㿪ʼ������clean��",
		"win" : (: ask_win :),
		"ʤ" : (: ask_win :),
		"lose" : (: ask_lose :),
		"��" : (: ask_lose :),

        ]) );
        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
                (: perform_action, "sword.xunlei" :),
        }) ); 

        setup();

        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/xingxiu/obj/wcloth")->wear();

}


void init()
{
    add_action("do_clean", "clean");
}

int do_clean()
{
    object me = this_player();
	int win, lose, draw, all;

	win = me->query("c_chess/win");
	lose  = me->query("c_chess/lose");
	draw  = me->query("c_chess/draw");
	all = win + lose + draw;
	
	if(all < 20) {
	return notify_fail("�����ۻ�����ʮ�������������¼�¼�ɼ���\n");
	}

    	me->delete("c_chess/win");
    	me->delete("c_chess/lose");
    	me->delete("c_chess/draw");
    	command("say �ã�"+RANK_D->query_respect(me) +"������ʤ����¼�Ѿ�ȫ������ˡ�\n");
    return 1;
}

int ask_score()
{
	object me = this_player();
	int win, lose, draw, all;
	string msg;
	
	win = me->query("c_chess/win");
	lose  = me->query("c_chess/lose");
	draw  = me->query("c_chess/draw");
	all = win + lose + draw;

	if (all < 1) {
	command("say "+RANK_D->query_respect(me) + "��û�и��˶��Ĺ��ɣ�");
	return 1;
	}

	msg = me->name()+RANK_D->query_respect(me) + 
	"��������"+chinese_number(all) +"�֣��ɼ���";

	if(win > 0)	msg += chinese_number(win) +"ʤ";
	if(lose > 0)	msg += chinese_number(lose) +"��";
	if(draw > 0)	msg += chinese_number(draw) +"��";
	msg += "��";
	
	command("say "+msg);
	if(all > 10) {
		if( lose > win*4 ) command("disapp "+me->query("id"));
		else if( lose > win ) command("nocry "+me->query("id"));

		if( win > lose*4 ) command("admire "+me->query("id"));
		else if(win > lose ) command("applaud "+me->query("id"));
		}
	return 1;
}

string ask_win()
{
	object where,obj,*ob_list;
	string msg, name;
	int i, win = 0, lose, draw, all;

	ob_list = users();

	for( i = 0; i < sizeof(ob_list); i++) {
		where = environment(ob_list[i]);
		if( ob_list[i]->query("c_chess/win") > win 
		&& where ) {
			obj = ob_list[i];
			win = obj->query("c_chess/win");
		}
	}
	if ( !obj ) {
		msg ="�ţ�ȫ�����ݡ����棬��û����������Ӯ���ġ�\n";
		return msg;
	}

	lose  = obj->query("c_chess/lose");
	draw  = obj->query("c_chess/draw");
	all = win + lose + draw;

	name = obj->query("name")+"("+obj->query("id")+")";
	msg ="˵���������ݡ���һ������֣��ǵ�Ȼ��"+name+"����ɼ���"+chinese_number(all)+"ս"+chinese_number(win)+"ʤ��\n";

	return msg;
}

string ask_lose()
{
	object where,obj,*ob_list;
	string msg, name;
	int i, lose = 0,win, draw, all;

	ob_list = users();

	for( i = 0; i < sizeof(ob_list); i++) {
		where = environment(ob_list[i]);
		if( ob_list[i]->query("c_chess/lose") > lose 
		&& where) {
			obj = ob_list[i];
			lose = obj->query("c_chess/lose");
		}
	}
	if ( !obj ) {
		msg ="ȫ�����ݡ���Ȼû��������������������Ǹ������Ǵ���֣�����û�˻����壿\n";
		return msg;
	}
	win = obj->query("c_chess/win");
	draw  = obj->query("c_chess/draw");
	all = win + lose + draw;

	name = obj->query("name")+"("+obj->query("id")+")";
	msg ="���ۡ����ݡ��������������ҵľ���"+name+"�ˣ��ɼ���"+chinese_number(all)+"ս"+chinese_number(lose)+"�ܡ�\n";

	return msg;
}