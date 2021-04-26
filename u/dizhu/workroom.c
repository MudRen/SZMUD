// date 29/3/2001 by spirit

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "[1;32mС������ũ��[37;0m");
  set ("long", @LONG
[1;32m
�ӻ������꣬����... ...
                     [1;36m���һ��ָ衷
[1;36m            �һ������һ��֣��һ������һ��ɡ� 
            �һ���������������ժ�һ�����Ǯ�� 
            ����ֻ�ڻ�ǰ���������������ߡ� 
            ���Ѱ����ո��գ����仨���긴�ꡣ 
            ��Ը�������Ƽ䣬��Ը�Ϲ�����ǰ�� 
            �����������Ȥ����յ��֦ƶ��Ե�� 
            ���������ƶ�ߣ�һ��ƽ��һ���졣 
            ����ƶ���ȳ������������ҵ��С� 
            ����Ц��߯��񲣬��Ц���˿������� 
            �����������Ĺ���޻��޾Ƴ����[37;0m
    baituo   �� �� ɽ      yuelao   �� �� ͤ       dali    �� �� ��
    emei     �� �� ɽ      gaibang  ؤ    ��       beijing ��    ��        
    huashan  ��    ɽ      kedian   ���ݿ͵�       xueshan ѩ    ɽ            
    leitai   ��    ̨      murong   ����Ľ��       shaolin �� �� ��          
    shenlong �� �� ��      towiz    �� �� ��       wiz     ��    ʦ            
    wudang   �� �� ɽ      wuguan   Ȫ�����       wumiao  ��    ��            
    xingxiu  �� �� ��      xuanjie  �� �� ��       taohua  ��    ��
LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/d/shaolin/npc/mu-ren" : 1,
]));
  set("exits", ([ /* sizeof() == 23 */
  "wudang" : "/d/wudang/sanqingdian",
  "xueshan" : "/d/xueshan/guangchang",
  "wumiao" : "/d/city/wumiao",
  "wuguan" : "/d/quanzhou/qianting",
  "wiz" : "/d/wizard/wizard_room",
  "towiz" : "/d/wizard/guest_room",
  "murong" : "/d/murong/qing4",
  "huashan" : "/d/huashan/pianting",
  "taohua" : "/d/taohua/jingshe",
  "shenlong" : "/d/shenlong/tingkou",
  "leitai" : "/u/xuy/bwdh/leitai",
  "xingxiu" : "/d/xingxiu/xxh2",
  "shaolin" : "/d/shaolin/guangchang1",
  "kedian" : "/d/city/kedian",
  "gaibang" : "/d/gaibang/undertre",
  "xuanjie" : "/d/qilian/datang",
  "yuelao" : "/d/city/yuelao",
  "emei" : "/d/emei/hz_guangchang",
  "guiyun" : "/d/taihu/qianyuan",
  "baituo" : "/d/xingxiu/btyard",
  "lingjiu" : "/d/lingjiu/main-22",
  "dali" : "/d/dali/wangfu1",
  "center" : "/d/wizard/center",
  "beijing" : "/d/beijing/kedian",
]));
  set("cost", 1);
  call_other("/clone/board/dizhu_b", "???"); 
  set("valid_startroom", 1);

  setup();
//  replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
	if (!wizardp(me))
		return notify_fail("���ᵲ������ǰ������˵�������ǳ���Ǹ�������ܵ��Ƕ�ȥ����\n");

	return ::valid_leave(me, dir);
}

int init()
{
        add_action("do_leave", "leave");
}

int do_leave()
{
	object me = this_player();
        tell_room(environment(me),
        "���ͻȻ����������"+(string)me->query("name")+"���䵽�˷��䡣\n",
        ({this_player(), me}));
        me->move("/d/city/wumiao");
       message("vision", me->name() + "ͻȻ�ӿ��е������������ʵʵˤ�˸�ƨ�ա�\n",
                environment(me), ({me}) );
	return 1;
}
