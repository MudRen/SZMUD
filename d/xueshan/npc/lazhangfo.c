// Code of ShenZhou

inherit NPC;

string ask_me();
string ask_me_book();

void create()
{
	set_name("���»��", ({ "lazhang huofo", "lazhang", "huofo" }));
	set("long", 
"���Ǳ��²ؾ�������ܣ�����Զ�������󾭣���ʱ��ʮ�ꡣ��ʮ����ʱ��ס���£�\n"
"�ڱ羭����϶�ռ��ͷ��������ȥ��Ƽ��ݣ������ݸߡ�\n");
	set("gender", "����");
	set("title","����������");
	set("age", 65);
	set("attitude", "friendly");
	set("class","bonze");
	set("shen_type", 1);
	set("str", 27);
	set("int", 33);
	set("con", 27);
	set("dex", 30);
	
	set("max_qi", 1400);
	set("max_jing", 850);
	set("jiali", 0);
	set("combat_exp", 50000);
	set("score", 5000);

	set("inquiry", ([
                "�ؾ�" : (: ask_me_book :),
		"�𷨽�ħ"       : (: ask_me :),
		"��������"	   : (: ask_me :),
        ]));

        set("book_count", 3);
	setup();
	carry_object(__DIR__"obj/lamajiasha")->wear();
       carry_object("/d/qilian/obj/fachu")->wield(); 
}
string ask_me_book()
{
	mapping fam;
        object ob;

        if (!(fam = this_player()->query("family")) || fam["family_name"] !="ѩɽ��"
	&& fam["family_name"] !="Ѫ����")
                return RANK_D->query_respect(this_player()) +
                "�뱾��������������֪�˻��Ӻ�̸��";
        if (query("book_count") < 1)
                return "�������ˣ����µľ��鲻�ڴ˴���";
        add("book_count", -1);
        ob = new("/d/xueshan/obj/fojing3.c");
        ob->move(this_player());
        return "�ðɣ��Ȿ�������û�ȥ�ú����С�";
}

#include "job.h"
