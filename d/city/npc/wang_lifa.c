// Code of ShenZhou
// �������npc��  by maco
// Modified by xQin 6/00

inherit NPC;
#include <ansi.h>

int ask_score();
string ask_win();
string ask_lose();

void create()
{
        set_name("���ϰ�", ({ "wang laoban", "wang", "laoban" }));
//        set("nickname", "");
        set("long", "����������������˵����������������������˴�����ݵ��ƹ�\n"
                    "Ϊ�˾����ܸɣ�����Щ��˽�������۲���������ڵ�����ʤ������\n"
                    "���Ը���Ҳ��¼���������������ʿ�ɼ���\n");
        set("gender", "����");
        set("age", 22);
        set("special_npc", 1);
        set("no_get", 1);
	set("title", "��������ƹ�");
        set("attitude", "friendly");
        set("str", 20);
        set("int", 26);
        set("con", 20);
        set("dex", 20);
        set("max_qi", 1000);
        set("max_jing",700);
        set("neili", 400);
        set("max_neili", 700);
        set("jingli", 3000);
        set("max_jingli", 700);
        set("jiali", 1);
        set("combat_exp", 50000);


        set_skill("force", 60);
        set_skill("dodge", 60);
        set_skill("parry", 60);
        set_skill("strike", 60);
        set_skill("literate", 60);
        set_skill("unarmed", 60);

        



        set("inquiry", ([
        	"tea" : "�͹�Ҫ�Ȳ���������Եط��ˣ�����������С������ϲ�㡣\n",
                "name" : "��������������������ƹ�\n",
                "������" : "�ұ��ǣ��͹ٿ��зԸ���\n",
                "Ʒ��" : "�ٺڣ�������Ĳ�ɶ��Ǽ�Ʒ�����͹������ſ���ȥ��������(help tea)��\n",
               	"�ɼ�" : (: ask_score :),
		"score" : (: ask_score :),
		"����" : "�������ָ���help c_chess�С�\n",
		"Χ��" : "Χ����Է�ڴ�����������˵����ҲҪ��һ���ˡ�\n",
		"����" : "�����Լ��ĳɼ������㿪ʼ������clean��",
		"abandon" : "�����Լ��ĳɼ������㿪ʼ������clean��",
		"clean" : "�����Լ��ĳɼ������㿪ʼ������clean��",
		"win" : (: ask_win :),
		"ʤ" : (: ask_win :),
		"lose" : (: ask_lose :),
		"��" : (: ask_lose :),

        ]) );
        setup();
//         add_money("gold", 1);
//        carry_object(__DIR__"obj/tiesuanpan")->wield();
        carry_object("/d/quanzhou/npc/obj/guazi")->wear();

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

int accept_kill(object me)
{
        command("say ���컯��֮�¾�������ɱ�ˣ�û��������\n");
        me->apply_condition("killer", 100);
        kill_ob(me);
        return 1;
}