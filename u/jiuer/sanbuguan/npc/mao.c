//Cracked by shenzhou
// mao.c éʮ��
// �ƶ�  May 2002

inherit NPC;

void create()
{
        set_name("éʮ��", ({ "mao shiba", "mao" }) );
        set("gender", "����" );
        set("age", 32);
        set("long", "����һλ�����ú���\n");
        
		set_skill("blade", 80);
		set_skill("wuhu-duanmen", 80);
        set_skill("dodge", 80);
		set_skill("wuxingbu", 80);
        set_skill("parry", 80);
        set_skill("wuhu-duanmen", 80);

        map_skill("dodge","wuxingbu");
		map_skill("parry","wuhu-duanmen");
		map_skill("blade","wuhu-duanmen");

        set("str", 30);
        set("int", 21);
        set("con", 24);
        set("dex", 26);

        set("max_neili", 800);
        set("jiali", 70);
		set("shen_type", 1);
     
		set("combat_exp", 50000);
        set("attitude", "peaceful");  
		
		set("chat_chance", 10);
		set("chat_msg", ({"éʮ�˹��ֵ����ֵ����ϲ����㣬�������������ˡ�\n",
			"éʮ��˵���� �����̵ģ��ҾͲ����������������������Ҫ�ϱ���ȥ����һ����\n",
			"éʮ������˵�����������ԣ���Ϊ�˲�ʶ�½��ϣ��ͳ�Ӣ��Ҳ��Ȼ����\n",
			"éʮ��̾��: �������廢���ŵ����Ը����ɿ��Ǵ´�����,ֻ��֪�Ը������в��С�\n",
		}) );
		setup();
        carry_object("/clone/armor/cloth")->wear();
        carry_object("/d/city/obj/gangdao")->wield();
}
