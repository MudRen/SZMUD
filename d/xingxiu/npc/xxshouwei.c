// Code of ShenZhou
// tianlang.c ������
inherit NPC;
void create()
{
	set_name("��������", ({ "xingxiu shouwei", "shouwei" }));
	set("long", 
		"���������ɵ���ͨ���ӡ�\n"
		"�������Գ�����ɫ���ࡣ\n");
	set("gender", "����");
	set("age", 30);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 27);
	set("int", 16);
	set("con", 25);
	set("dex", 27);
	
	set("max_qi", 1000);
	set("max_jing", 800);
	set("neili", 1500);
	set("max_neili", 1000);
	set("jiali", 15);
	set("combat_exp", 500000);
	set("score", 30000);

	set_skill("force", 100);
	set_skill("huagong-dafa", 100);
	set_skill("dodge", 100);
	set_skill("zhaixinggong", 100);
	set_skill("strike", 100);
	set_skill("chousui-zhang", 100);
	set_skill("poison", 100);
	set_skill("parry", 100);
	set_skill("staff", 100);
  	set_skill("tianshan-zhang", 100);
//	set_skill("literate", 50);

	map_skill("force", "huagong-dafa");
	map_skill("dodge", "zhaixinggong");
	map_skill("strike", "chousui-zhang");
  	map_skill("parry", "tianshan-zhang");
  	map_skill("staff", "tianshan-zhang");

	prepare_skill("strike", "chousui-zhang");

	create_family("������", 3, "����");
        set("inquiry",
           ([
           "����" : "�����������˳��Űݻ�����ͬ���������ǻ�������ڣ�",
           ]));
	setup();
  	carry_object("/clone/weapon/gangzhang")->wield();
	carry_object("/d/xingxiu/obj/yellow-cloth")->wear();
}
void init()
{
}

int accept_object(object who,object ob)
{
        if( !who || environment(who) != environment() ) return 0;
        if ( !objectp(ob) ) return 0;
        if ( !present(ob, who) ) return notify_fail("��û�����������\n");

        if (  (string)ob->query("name") == "����")
           {    tell_object(who,"������������һ�°������ֿ��������ۡ�\n");
                if(who->query("name")!=ob->query_temp("owner"))
                        return notify_fail("�������������ȣ����ⲻ�����Լ��İ������㵽���к���ͼ����\n");
                else
                {       switch(random(4)){
                        case(0):
                                tell_object(who,"������������˵���������ɽ��ղ���ӭ�ݷã��㻹����ذɡ���\n");
                                break;
                        case(1):
                                tell_object(who,"���������������˵������ү�ҽ��첻���˴��������������������\n");
                                break;
                        case(2):
                                tell_object(who,"������������˵���������¼�Ȼ��" + ob->query_temp("fam") +"�����ѣ��Ǿ����ɡ��� \n");
                                who->set_temp("xx_pass");
                                break;
                        case(3):
                                tell_object(who,"���������𾴵Ķ���˵������" + ob->query_temp("fam") + "�������£�������Ա�ɡ��� \n");
                                who->set_temp("xx_pass");
                                break;
                        case(4):
                                tell_object(who,"����������ݺݵĶ���˵����������" + ob->query_temp("fam") +"�����ǽ��µ����ӻ�û�壬��������㿪������ \n");
                                kill_ob(who);
                                ob->stat_busy(1);
                                break;
                        }
                  }
         }
         return 1;

}

                

