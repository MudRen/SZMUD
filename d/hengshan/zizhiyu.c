//Cracked by Roath
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "��֥��");
        set("long", 
"˳ͨԪ��ʰ�׶��ϣ��㵽����֥������������ͷ׳�����
��ɫ��֪����Ұ�������������ҩ���������С��ݴ����а���
��֥���������Σ������������֥������\n"
        );
        set("exits", ([
                "eastup"  : __DIR__"longquanguan",
                "southwest"  : __DIR__"daziling",
]));
        set("no_clean_up", 0);
        set("outdoors", "hengshan");
        set("cost", 1);
        setup();
       // replace_program(ROOM);
}
/*void init()
{
          add_action("do_search","search");
}
int do_search(string arg)
{	
	int fuyuan;
	object ob,me;
      me = this_player();
	fuyuan = me->query("kar");
      if (arg != "grass")
        return notify_fail("��Ҫ���Ķ���? \n");
	else
	{
                if (query("searched"))
                        return notify_fail("���ڲݴ�����Ѱ��һ�������ʲô��û�ҵ���\n");
		else{ 
		if (random(fuyuan) >15)
		{
		        ob = new("/clone/drug/lingzhi");
	        	set("searched",1);              
                	message_vision("�������ܵ�ɽ���в��ϵ���Ѱ�ţ���Ȼ�ڲݴ�֮�з�����һ����֥"��\n",me);
                	ob->move(me);
                	return 1;
        	}
	else return 0;
	}       

}*/