inherit NPC;
void create()
{	set_name("�ܼ���",({"room master","master"}));
	set("title","���ݴ�ַ���");
	set("gender","Ů��");
	set("age",22);
        set("combat_exp",10000);
	set("attitude","heroism");
	setup();
	carry_object("/d/city/obj/cloth")->wear();
}
#include "master_func.c"
