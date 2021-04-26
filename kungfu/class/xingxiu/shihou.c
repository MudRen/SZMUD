// Code of ShenZhou
// shihou.c ʨ����

inherit NPC;
inherit F_MASTER;

string ask_me();

void create()
{
        set_name("ʨ����", ({ "shihou zi", "shihou" }));
        set("nickname", "�����ɶ�ʦ��");
        set("long", 
                "�����Ƕ�����Ķ�����ʨ���ӡ�\n"
                "��ʨ�����ڣ�һ����֪����������ʿ��\n");
        set("gender", "����");
        set("age", 32);
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("str", 28);
        set("int", 20);
        set("con", 26);
        set("dex", 22);
        
        set("max_qi", 1500);
        set("max_jing", 500);
        set("neili", 2000);
        set("max_neili", 2000);
        set("jiali", 40);
        set("combat_exp", 200000);
        set("score", 30000);

        set_skill("force", 120);
        set_skill("huagong-dafa", 120);
        set_skill("dodge", 120);
        set_skill("zhaixinggong", 120);
        set_skill("poison", 70);
        set_skill("strike", 120);
        set_skill("parry", 120);
        set_skill("chousui-zhang", 120);
        set_skill("staff", 120);
        set_skill("tianshan-zhang", 120);

        map_skill("force", "huagong-dafa");
        map_skill("dodge", "zhaixinggong");
        map_skill("strike", "chousui-zhang");
        map_skill("parry", "tianshan-zhang");
        map_skill("staff", "tianshan-zhang");

        prepare_skill("strike", "chousui-zhang");

        create_family("������", 2, "����");

        setup();
        carry_object("/d/xingxiu/obj/yellow-cloth")->wear();
}

void attempt_apprentice(object me)
{
        if( me->query("family/family_name") == "ؤ��"
        && me->query("combat_exp") >= 10000 ) {
                command ("say ����������޽л��ӣ��ҿɲ������㡣");
                return;
	}
	
	if ((int)me->query("shen") > -10000) {
                command("say ����Խ����Խ��׵������Ե׵ġ�");
                return;
        }
	
        command("say �ðɣ��Ҿ��������ˡ�");
        command("recruit " + me->query("id"));
}
