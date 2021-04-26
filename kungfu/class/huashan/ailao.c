// Code of ShenZhou
// ailao.c ������
// qfy Sept 8, 1996.
//add ailao's basic force to 400 by xiaojian Oct 18,2000
inherit NPC;
inherit F_MASTER;

int auto_perform();

void create()
{
	set_name("������", ({ "ai lao", "ai", "lao" }));
	set("long", 
"����������С�������ȷǷ������˲���С����������ʦ�ܸ�����\n"
"�չ��Ѿã������������������书֮�ߣ�ȴ�����𾪡�\n");
	set("gender", "����");
	set("age", 75);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 27);
	set("int", 25);
	set("con", 25);
	set("dex", 26);
	
	set("max_qi", 4500);
	set("max_jing", 3200);
	set("neili", 5000);
	set("max_neili", 5000);
	set("jiali", 100);
	set("combat_exp", 3500000);
	set("score", 5000);

	set_skill("force", 400);
	set_skill("dodge", 300);
	set_skill("parry", 300);
	set_skill("blade", 340);
	set_skill("sword", 340);
	set_skill("strike", 300);
	set_skill("liangyi-dao", 340);
	set_skill("huashan-jianfa", 340);
	set_skill("hunyuan-zhang",300);
	set_skill("huashan-shenfa", 300);
	set_skill("zixia-gong", 360);
	set_skill("cuff", 300);
	set_skill("pishi-poyu", 300);
	set_skill("ziyin-yin", 360);
	set_skill("zhengqi-jue", 360);

	map_skill("cuff", "pishi-poyu");
	map_skill("force", "zixia-gong");
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
	    "��ϼ��" : "���Ǳ������ߵ��ڹ��ķ�����˵��ϼ����ȱ������һҳ����ϧ���������޷���͸������\n",
	    "��ϼ��" : "���Ǳ������ϵ��ڹ��ķ�����˵��ϼ����ȱ������һҳ����ϧ���������޷���͸������\n",
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
