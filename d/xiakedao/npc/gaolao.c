//Cracked by Roath
// gaolao.c ������
// qfy Sept 8, 1996.

inherit NPC;

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
        
        set("max_qi", 3000);
        set("max_jing", 2000);
        set("neili", 2500);
        set("max_neili", 2500);
        set("combat_exp", 1500000);
        set("score", 5000);

        set_skill("force", 160);
        set_skill("dodge", 170);
        set_skill("parry", 160);
        set_skill("blade", 180);
        set_skill("sword", 160);
        set_skill("strike", 150);
        set_skill("liangyi-dao", 180);
        set_skill("huashan-jianfa", 160);
        set_skill("hunyuan-zhang",150);
        set_skill("huashan-shenfa", 150);
        set_skill("zixia-gong", 160);
        set_skill("cuff", 150);
        set_skill("pishi-poyu", 150);
        set_skill("ziyin-yin", 130);
        set_skill("zhengqi-jue", 130);

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

        setup();
        carry_object("/clone/weapon/gangdao")->wield();
        carry_object("/d/city/obj/cloth")->wear();
}

#include "/d/xiakedao/npc/zhanglao.h"