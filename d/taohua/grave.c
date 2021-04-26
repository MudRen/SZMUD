// Code of ShenZhou
//kane

inherit ROOM;

void create()
{
	set("short", "Ĺ��");
	set("long", @LONG
Ĺ��������һ���㰸�����Ϲ��Ż�ҩʦ���˷�����λ����ǰ����յ�����ƣ�
��Ƶĵƹ�ӳ�Ż�ҩʦ�ֻ�ķ�������(portrait)��Ĺ���бڼ䰸ͷ���ǹ�����
�棬�����鷨����һ���Ǽ�ֵ���ǵľ�Ʒ����ҩʦ�����ݺ���������޵�������
��������������ʱ����������Ĺ��֮�У�ֻ���䱦����Щ��������������֮
���ڵƹ��·���������â���鰸��һ��ձᡣ������Ƿ��ϵ���ס�
LONG
	);
        
	set("item_desc", ([
        "portrait" : 
"\n�Ʒ��˷�����Ŀ������������������ʺ��գ�һ�����˾�����ز��\n"
        ]));

        set("exits", ([
                "out" : __DIR__"didao",
        ]));

        set("objects", ([
                "/d/taohua/obj/coffin" : 1,
        ]));
	
	setup();
//	replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
	object ob;
	
	ob = present("coffin", environment(me));
	ob->delete("opened");  
	ob->set("long", "����һ������������ɵ�ʯ�ף���Ө��࣬ʵ�ǿ�����Ѱ�����\n");
  	
	return ::valid_leave(me, dir);
}

int is_container() { return query("opened"); };

