/*-------------------------------------------------------------
** �ļ���: guanshi.c
** Copyright (c) 2000-2001
** ������: ��ݹ�����
** ��  ��: 2001/08/13
** ��  ��: ��ݻ���
**-----------------------------------------------------------*/

inherit NPC;
string random_chat();

void create()
{
        set_name("����", ({ "hua jiang","jiang","huajiang" }) );
        set("gender", "����");
        set("age", 50);
        set("long",
                "����һλ�ϻ�����������д����������ݵĹ�����\n");
        set("combat_exp", 3000);
        set("shen_type", 1);
        set("attitude", "peaceful");

        set("apply/attack", 10);
        set("apply/defense", 10);

        set_skill("blade", 35);
        set_skill("unarmed", 35);
        set_skill("parry", 35);
        set_skill("dodge", 35);
        
        set("chat_chance", 50);
	set("chat_msg", (: random_chat :));

        setup();

        carry_object("/d/dali/obj/huachu")->wield();
        carry_object("/clone/misc/cloth")->wear();
        add_money("silver", 1);
}

int random_chat() {

    switch (random(200)) {
    case 0:
        command("say ��ӭ����������ݡ�");
	return 1;
    case 1:
        command("say �����кö��������С�Ĳ�Ҫ�Ȼ��ˡ�");
	return 1;
    case 2:
        command("say �㲻Ҫ�ɻ�������������������������ġ�");
	return 1;
    case 3:
        command("say ��������˺ö��Ǯ�����˺ܶ��������");
	return 1;
    case 4:
        command("say ����Ļ������ҵ�ʦ�֣��ҵ����ղ������");
	return 1;
    default:
	return 0;
    }
    return 1;
}

