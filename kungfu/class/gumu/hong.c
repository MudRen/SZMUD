// Code of ShenZhou
// Xuanyuan 7/14/2001

#include <ansi.h>
inherit NPC;
int auto_perform();
void create()
{
        set_name("���貨", ({ "hong lingbo", "hong", "lingbo" }));
        set("long", "��������Ī��ĵ�����ӡ�\n");
        set("gender", "Ů��");
        set("rank_info/respect", "����");
        set("age", 20);
        set("attitude","heroism");
        set("str", 20);
        set("dex", 20);
        set("con", 20);
        set("int", 20);
        set("shen_type", -1);

        set_skill("strike", 100);
        set_skill("cuff", 100);
	set_skill("gumu-shenfa", 100);
	set_skill("chilian-shenzhang", 100);
	set_skill("meinu-quan", 100);
        set_skill("force", 100);
        set_skill("dodge", 100);
        set_skill("whip",100);
	set_skill("throwing",100);
	set_skill("jueqing-bian",100);
        set_skill("wudu-xinfa",100);

	map_skill("dodge", "gumu-shenfa");
	map_skill("strike", "chilian-shenzhang");
	map_skill("cuff", "meinu-quan");
        map_skill("force", "wudu-xinfa");
	map_skill("whip","jueqing-bian");

	prepare_skill("strike", "chilian-shenzhang");

        set("jiali",50);
        set("combat_exp", 300000);

        set("max_qi", 2100);
        set("max_jing", 3200);
        set("neili", 2000);
        set("max_neili", 2000);

        create_family("��Ĺ��",4,"����");

        set("inquiry", ([
            "name" : "վԶ�㣡",
            "here" : "�Ҳ��Ǳ����ˣ���֪����",
            "С��Ů" : "������ʦ����ʦ�á�����ʦ�塣",
            "�ֳ�Ӣ" : "��ʦ��˵�����ҵ�ʦ�棬",
       ]) );

        setup();
	set("chat_chance_combat", 50);
	set("chat_msg_combat", ({
		(: auto_perform :),
	}) );
        carry_object("/clone/weapon/fuchen")->wield();
        carry_object("/d/wudang/obj/greenrobe")->wear();
}
#include "/kungfu/class/gumu/auto_perform.h";
