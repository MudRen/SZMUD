// Code of ShenZhou
//kane

inherit ROOM;

void create()
{
	set("short", "��ڣ");
	set("long", @LONG
һת�����֣���Ȼ������һƬ��ɫ���ԣ����ص���������һ���׻��ѳɵ�С����
�׻�֮����һ�鶫���߸�¡�𣬶���һ����ԭ����һ��ʯ�أ���ǰĹ��(mubei)�Ͽ���
���һ���Ů����������֮ڣ��ʮһ�����֡�Ĺǰ��ʱ�ʻ�������ÿ�����ǻ�ҩʦ��ѡ
���������֣��滨��ܣ����Է������ޡ�
LONG
	);
	set("item_desc", ([
                "mubei" : "Ĺ�����������������бб��С�֣��ҷ����Ϊ¯�⣬�컯Ϊ��������Ϊ̿�⣬\n"
			  "����Ϊͭ��\n"
			  "Ĺ�����棬���棬�����ƺ��ر�⻬��\n",
        ]));
        
	set("exits", ([
                "east" : __DIR__"taolin",
        ]));
      	
	
	set("cost", 2);
	set("outdoors", "taohua");

	setup();
//	replace_program(ROOM);
}

void init()
{
  add_action("do_push","push");
}

int do_push(string arg)
{
  	object me = this_player();

  	if (!arg) return 0;

        if ( (int)me->query_str() < 28 ) {
                return notify_fail("��û��ô�������ᶯĹ����\n");
        }  
  	
	if (arg == "left") {
    	add_temp("left",1);
    	write("Ĺ��ҡ����һ���ٲ�������...\n");
  	}

  	if ((arg == "right") && ((int)query_temp("left")==3)) {
    	add_temp("right",1);
    	write("Ĺ��ҡ����һ���ٲ�������...\n");
  	}

  	if ((arg == "front") && ((int)query_temp("right")==3) && ((int)query_temp("left")==3)) {
    	write("Ĺ��ҡ����һ�󣬻������ȥ��¶��һ����ڡ�\n");
    	set("exits/enter", __DIR__"didao");
    	remove_call_out("close_door");
    	call_out("close_door",15,me);
  	}

  	return 1;
}

void close_door()
{

  if (((int)query_temp("left")!=3) || ((int)query_temp("right")!=3)) return;

  	delete("exits/enter");
  	delete_temp("left");
  	delete_temp("right");
}
