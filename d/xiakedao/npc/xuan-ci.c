//Cracked by Roath
// Npc: /kungfu/class/shaolin/xuan-ci.c
// Date: YZC 96/01/19

inherit NPC;

void create()
{
        set_name("���ȴ�ʦ", ({
                "xuanci dashi",
                "xuanci",
                "dashi",
        }));
        set("long",
                "����һλ�����ü����ɮ����һϮ��˿������ġ�\n"
                "������������ͣ���ȴ�����⣬Ŀ�̴�Ц���Ե��������㡣\n"
        );
        
        
        set("nickname", "�����·���");
        set("gender", "����");
        set("attitude", "friendly");
        set("class", "bonze");
        
        set("age", 70);
        set("shen_type", 1);
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        set("max_qi", 1500);
        set("max_jing", 1000);
        set("neili", 2000);
        set("max_neili", 2000);
        set("combat_exp", 900000);
        set("score", 500000);
        
        set_skill("force", 200);
        set_skill("hunyuan-yiqi", 200);
        set_skill("dodge", 200);
        set_skill("shaolin-shenfa", 210);
        set_skill("finger", 200);
        set_skill("strike", 200);
        set_skill("hand", 114);
        set_skill("claw", 200);
        set_skill("parry", 200);
        set_skill("nianhua-zhi", 200);
        set_skill("sanhua-zhang", 200);
        set_skill("fengyun-shou", 200);
        set_skill("longzhua-gong", 200);
        set_skill("buddhism", 200);
        set_skill("literate", 200);
        
        map_skill("force", "hunyuan-yiqi");
        map_skill("dodge", "shaolin-shenfa");
        map_skill("finger", "nianhua-zhi");
        map_skill("strike", "sanhua-zhang");
        map_skill("hand", "fengyun-shou");
        map_skill("claw", "longzhua-gong");
        map_skill("parry", "nianhua-zhi");
        
        prepare_skill("finger", "nianhua-zhi");
        prepare_skill("strike", "sanhua-zhang");
        
        create_family("������", 36, "����");
        set("chat_chance", 20);
        set("chat_msg", ({
                "���ȴ�ʦ������Ȼ����Ȼ��\n",
                "���ȴ�ʦ�������⹳֮�����������ƣ�Բת���⡣\n",
        }) );

        setup();

        carry_object("/d/shaolin/obj/xuan-cloth")->wear();
}

void attempt_apprentice(object ob)
{
        command ("say �⡸�����С��Ĺ�ʫͼ�⣬�����Ź������������
����ѧ�ذ£��Ϸ�߾����ǣ����Բ��ܲ�������ʮ֮һ�����ǻ��ܷ�
��ȥ����������¡� ");
}


