inherit NPC;
void create()
{       
        set_name("�������ϰ�",({"boss","lao ban",}));
        set("nickname","ף������");
        set("long","�����ǲ����е��ϰ塣���Ϲ������˵�����Ц�ݡ�\n");
        set("age", 20);
        set("gender","����");
        set("inquiry",([
                "��Ʊ" : "��ӵ�еĲ�Ʊ���Խ����д�������Խ���\n",
                "Ƥ��" : "����������д�Ҫ�ɡ�\n",
                "��Ʊ��": "�����Ǹ����и�����Ʊ�;��п������Խ�����������е���\n",
        ]));    
        setup();

        carry_object("/clone/armor/cloth")->wear();
        set("chat_chance",1);
        set("chat_msg", ({
                "�������ϰ�Ц���е�˵������ӭ��Ҳ��븣����Ʊ�������ף����ˡ�\n",
        }) );
}

