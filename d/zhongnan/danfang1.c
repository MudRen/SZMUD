// Code of ShenZhou
///d/zhongnan/danfang1.c
//sdong 07/98

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
������һ������������������λ���������ĵط�������һ�������(shelf)��
����ҩ�ĺ�����С��ƿ��������һֻ����¯�������о���ҩζ��������һ������
(chair)��
LONG
        );
        set("no_clean_up", 0);

        set("item_desc", ([
        "chair" : 
"һ�����ӣ�Ĩ�õúܸɾ����α�����˫�������ͼ�����������̵�
����������������צ������һ�������α�����ⷢ��������(Ball)��\n",
        "shelf" :
"һ������ӣ��ѷ��˲��ٶ���������(search)û׼���кö�����\n",
        ]));

		  set("objects", ([
				__DIR__"obj/danlu" : 1,
					 ]));

		 setup();
}


void init()
{
        add_action("do_turn","zhuan");
        add_action("do_turn","turn");
        add_action("do_search","search");
}

int do_turn(string arg)
{
        object me;
        me = this_player();
        if( !arg || arg == "" ) return 0;
        if( arg == "ball" || arg == "qiu")
        {
        message_vision("$N��������һ�����ӣ��������α�������һ������\n\n"+
        "�������Ż�����һ����ȥ��¶��һ�����ڡ�\n",me);
        set("exits/east", __DIR__"xilang");
        remove_call_out("close_door");
        call_out("close_door",15,me);

                return 1;
        }
        else
                return notify_fail("��Ҫ��ʲô��\n");
}

void close_door(object me)
{
        tell_room(this_object(),"���������ֻ������˻�����\n");
        delete("exits/east");
}

int do_search(string arg)
{
        object ob,me;
        me = this_player();
        if (!arg || arg == "") return 0;
        
        if (arg == "jia" || arg == "shelf")
        {
                if (query("searched",1)>10)
                        return notify_fail("���ڼ����Ϸ�Ѱ��һ�󣬵�ʲô��û�ҵ���\n");

                switch (random(7))
                {
                        case 0:
                        ob = new(DRUG_D("huanzhi"));
                        break;
                        case 1:
                        ob = new(DRUG_D("tongshen"));
                        break;
                        case 2:
                        ob = new(DRUG_D("shengjing"));
                        break;
                        case 3:
                        ob = new(DRUG_D("dingyang"));
                        break;
                        case 4:
                        ob = new(DRUG_D("zhaohun"));
                        break;
                }

                set("searched",query("searched",1)+1);              
                message_vision("���һ��Сƿ�����ҵ�һ��"+ob->query("name")+"��\n",me);
                ob->move(me);
                return 1;
        }
}     
