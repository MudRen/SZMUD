//By oytj 2002.08.05

#include <room.h>
#include <ansi.h>
inherit ROOM;
void create ()
{
  set ("short", HIW"���ʺ�"NOR);
  set ("long",HIW"

������� �S�L���w\n"HIC

"              
                      �����ɫ \n
                   һ�γ�ɫ�Ļ���
                   һ����ɫ��ϴ��
                   һ�������Զ��
                   ���Ҹ��и�ǳ....
                   �ǵã��������£�������ʧ�˺ܶණ��
                   �ǵã��������£��һ�������һ��ǣ��
                   �ǵã��������£���������һ���ʺ�\n"NOR"


    "HIR"baituo"NOR"   "HIW"�� �� ɽ"NOR"      "HIR"yuelao"NOR"   "HIW"�� �� ͤ"NOR"       "HIR"dali"NOR"    "HIW"�� �� ��"NOR"
    "HIR"emei"NOR"     "HIW"�� �� ɽ"NOR"      "HIR"gaibang"NOR"  "HIW"ؤ    ��"NOR"       "HIR"beijing"NOR" "HIW"��    ��"NOR"        
    "HIR"huashan"NOR"  "HIW"��    ɽ"NOR"      "HIR"kedian"NOR"   "HIW"���ݿ͵�"NOR"       "HIR"xueshan"NOR" "HIW"ѩ    ɽ"NOR"            
    "HIR"gumu"NOR"     "HIW"��    Ĺ"NOR"      "HIR"kunlun"NOR"   "HIW"�� �� ɽ"NOR"       "HIR"shaolin"NOR" "HIW"�� �� ��"NOR"          
    "HIR"shenlong"NOR" "HIW"�� �� ��"NOR"      "HIR"towiz"NOR"    "HIW"�� �� ��"NOR"       "HIR"wiz"NOR"     "HIW"��    ʦ"NOR"            
    "HIR"wudang"NOR"   "HIW"�� �� ɽ"NOR"      "HIR"wuguan"NOR"   "HIW"Ȫ�����"NOR"       "HIR"wumiao"NOR"  "HIW"��    ��"NOR"            
    "HIR"xingxiu"NOR"  "HIW"�� �� ��"NOR"      "HIR"xuanjie"NOR"  "HIW"�� �� ��"NOR"       "HIR"taohua"NOR"  "HIW"��    ��"NOR"\n"

 );

        set("objects", ([ /* sizeof() == 1 */ 
  "/u/oytj/npc/konglong.c" : 1,  
  "/u/oytj/obj/atm.c" : 1, 
  "/u/oytj/obj/zizhu.c" : 1,
  "/u/oytj/npc/peilian.c" : 2,
  "/u/oytj/npc/xx.c" : 1,
  "/u/oytj/obj/dragon.c" : 1,
]));
  set("exits", ([ /* sizeof() == 23 */
  "wudang" : "/d/wudang/sanqingdian",
  "xueshan" : "/d/xueshan/guangchang",
  "wumiao" : "/d/city/wumiao",
  "wuguan" : "/d/wuguan/zhengting",
  "wiz" : "/d/wizard/wizard_room",
  "towiz" : "/d/wizard/guest_room",
  "kunlun" : "/d/kunlun/sanshengtang",
  "huashan" : "/d/huashan/pianting",
  "taohua" : "/d/taohua/jingshe",
  "shenlong" : "/d/shenlong/tingkou",
  "xingxiu" : "/d/xingxiu/xxh2",
  "shaolin" : "/d/shaolin/guangchang1",
  "kedian" : "/d/city/kedian",
  "gaibang" : "/d/gaibang/undertre",
  "xuanjie" : "/d/qilian/datang",
  "yuelao" : "/d/city/yuelao",
  "emei" : "/d/emei/hz_guangchang",
  "guiyun" : "/d/taihu/qianyuan",
  "baituo" : "/d/baituo/lingshege",
  "dali" : "/d/dali/wangfu1",
  "gumu" : "/d/gumu/dating",
  "beijing" : "/d/beijing/yiyantang",
]));
  set("cost", 1);
  set("valid_startroom", 1);

       call_other("/clone/board/oytj_b", "???"); 

  setup();
//  replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
	if (!wizardp(me))
		return notify_fail("С��ʹ��������ǰ������˵�������ǳ���Ǹ�������ܵ��Ƕ�ȥ����\n");

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
