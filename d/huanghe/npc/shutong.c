//npc: /d/city/npc/shutong.c  ����С��
//piao  2001/09/14
inherit NPC;
void create()
{       
        set_name("С��",({"xiao yue","xiao","shutong",}));
        set("title","�챦������");
        set("long","�������ֺ����ģ�����һ˫�����ۣ�����ʮ�ֿɰ���\n");
        set("age", 14);
        set("gender","Ů��");
        set("inquiry",([
                "����":"�����кܶ�ݸ壬����λ����������(copy)�ɡ�\n",
                "age":"�ҽ���ʮ��������\n",
                "ѧλ":"���ѽ����Ҫȥ����������֪����\n",    
                "�ƾ�":"���뿼ȡ����ѽ���Ǿͺúö����\n",
        ]));    
        setup();

        carry_object("d/city/obj/pink_cloth")->wear();
        carry_object("d/city/obj/flower_shoe")->wear();

        set("chat_chance",3);
        set("chat_msg", ({
                "С��˵��������ү˵�����������������֪ʶ��\n",
                "С��˵�������������ѧ�����ٺö���Ŷ��\n",
                "С��˵����������ү��ѧ�ʿɺ�����\n" ,                "С��˵�������˰ɣ�Ҫ��Ҫ��Ϣһ�¡�\n",
                "С������̨����˵�ˮ��ʹ��ĥ��������\n" ,        }) );

}

