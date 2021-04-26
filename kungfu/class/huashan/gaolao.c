// Code of ShenZhou
// gaolao.c ������
// qfy Sept 8, 1996.

inherit NPC;
inherit F_MASTER;

int auto_perform();

void create()
{
	set_name("������", ({ "gao lao", "gao", "lao" }));
	set("long", 
"�����θߴ�˶״�������⡣��ֹ����������ɵ�����书ȴ�Ǽ��ߡ�\n"
"���򲻳��ڽ�����¶�棬���Բ���̫����֪��������\n");
	set("gender", "����");
	set("age", 73);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 27);
	set("int", 20);
	set("con", 27);
	set("dex", 25);
	
	set("max_qi", 4300);
	set("max_jing", 3000);
	set("neili", 4500);
	set("max_neili", 4500);
	set("jiali", 100);
	set("combat_exp", 3200000);
	set("score", 5000);

	set_skill("force", 320);
	set_skill("dodge", 300);
	set_skill("parry", 300);
	set_skill("blade", 330);
	set_skill("sword", 320);
	set_skill("strike", 300);
	set_skill("liangyi-dao", 330);
	set_skill("huashan-jianfa", 320);
	set_skill("hunyuan-zhang",300);
	set_skill("huashan-shenfa", 300);
	set_skill("zixia-gong", 320);
	set_skill("cuff", 300);
	set_skill("pishi-poyu", 300);
	set_skill("ziyin-yin", 300);
	set_skill("zhengqi-jue", 300);

	map_skill("cuff", "pishi-poyu");
	map_skill("force", "zixia-gong");
	map_skill("parry", "huashan-jianfa");
	map_skill("blade", "liangyi-dao");
	map_skill("sword", "huashan-jianfa");
	map_skill("strike", "hunyuan-zhang");
	map_skill("dodge", "huashan-shenfa");
	
	prepare_skill("strike", "hunyuan-zhang");
	prepare_skill("cuff", "pishi-poyu");

	create_family("��ɽ��", 12, "����");

	set("inquiry", ([
	    "��ϼ��" : "���Ǳ������ߵ��ڹ��ķ�����˵��ϼ�и������ܣ���ϧ��ʧ�������ˡ�\n",
	    "��ϼ��" : "���Ǳ������ϵ��ڹ��ķ�����˵��ϼ�и������ܣ���ϧ��ʧ�������ˡ�\n",
	    "˼����" : "���Ǳ��ɵ�������˼��֮����\n",
            "��ϼ����" : "�����ϼ�������ϰ��ϼ�����ķ���\n",
	    "��ϼ�ܼ�" : "�ܼ��ϼ�������ϰ��ϼ�����ķ���\n",
	    "����" : "���˵�˵�Щ���᣿\n",
	]));

	set("chat_chance_combat", 50);
	set("chat_msg_combat", ({
		(: auto_perform :),
	}) );

	setup();
	carry_object("/clone/weapon/gangdao")->wield();
	carry_object("/d/city/obj/cloth")->wear();
}

#include "/kungfu/class/huashan/zhanglao.h"
