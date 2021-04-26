//Cracked by Roath
// mizheng.c ��������
// ��������٣��ʹ��������ͷ�����¼����Ǩ��������	-chu

#include <ansi.h>
#ifndef NPCDATA
#define NPCDATA "/data/npc/"
#endif

inherit NPC;
inherit F_SAVE;

string do_toujun();
string do_tuiyi();
string do_shengqian();

void create()
{
    seteuid(getuid());
    if (! restore()) {
	set_name("����", ({"mi zheng", "mi"}));
	set("title", "��������");
	set("gender", "����");
	set("age", 30);
	set("long", "�����ǵ���͢�ı������飬\n"
	"������������ٵ���Ǩ��ȫ�����ˡ�\n");
	set("attitude","heroism");
	set("generation",0);

	set("max_qi",800);
	set("eff_qi",800);
	set("qi",800);
	set("max_jing",300);
	set("jing",300);
	set("shen_type",1);
	set("no_clean_up",1);
	set("combat_exp",20000);

	setup();
	carry_object("/d/city/obj/cloth")->wear();
	save();
    }
}

int init()
{
	set("inquiry", ([
	"���" : "�����ȥ�ʾ�Ӫ�Ķ��ܹܰɡ�\n",
	"����" : "�����ȥ�ʾ�Ӫ�Ķ��ܹܰɡ�\n",
	"Ͷ��" : (: do_toujun :),
	"��Ǩ" : (: do_shengqian :),
	"����" : (: do_tuiyi :),
	]));
}

string query_save_file()
{
    return NPCDATA+"mizheng";
}

string do_shengqian()
{
    return "�ȵ�";
}

string do_tuiyi()
{
    return "�ȵ�";
}

string do_toujun()
{
    return "�ȵ�";
}
