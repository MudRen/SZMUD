// Code of ShenZhou
// Room: /u/xqin/workroom.c

inherit ROOM;
#include <ansi.h>
void init();
string look_dashi();

void create()
{
        set("short", HIW "ˮ�Ƽ�" NOR);
        set("long", @LONG
����������ɽ�����ȣ������������������ͱڡ��������£�������
�����ɽ����һ�����ٲ����������գ��������£�����һ���峺�쳣�Ĵ��
�С��ٲ�ע�봦��ˮ����������ٲ�ʮ���ɣ���ˮ��һƽ�羵���������¹�
������У�����Ҳ��һ�����Բ��(moon)��
LONG
        );
        set("valid_startroom", 1);
     //   call_other("/clone/board/xqin_b", "???");
        
        set("exits", ([
                "gb" : "/d/gaibang/undertre",
  		"sl" : "/d/shaolin/guangchang1",
	        "bt" : "/d/xingxiu/btyard",
  		"yz" : "/d/city/kedian",
  		"xx" : "/d/xingxiu/xxh2",
  		"zn" : "/d/zhongnan/taijie2",
  		"th" : "/d/taohua/jingshe",
  		"hs" : "/d/huashan/pianting",
  		"sh" : "/d/shenlong/tingkou",
  		"wd" : "/d/wudang/sanqingdian",
  		"xs" : "/d/xueshan/guangchang",
  		"dl" : "/d/dali/wangfu1",
  		"em" : "/d/emei/hz_guangchang",
  		"xk" : "/d/xiakedao/dadong",
  		"gy" : "/d/taihu/qianyuan",
  		"bj" : "/d/beijing/kedian",
  		"xy" : "/d/xiangyang/kedian",
  		"kt" : "/d/city/kantai",
  		"qz" : "/d/quanzhou/qianting",
  		"ft" : "/d/city/ft_datang",
  		"xj" : "/d/qilian/datang",
  		"wiz" : "/d/wizard/wizard_room",
  		"pig" : "/d/city/duchang2",
  		"blk" : "/d/death/blkbot",
        ]));

                set("objects", ([
                "d/city/npc/obj/flower/white_rose" : 1,
        ]));

    set("item_desc",([
        "dashi"        : HIW"  
     �� �� �� �� �� ʱ ֻ ��  �� �� �� ��  Ը �� �� �� �� �� �� ��  �� �� �� һ
     �� �� �� һ �� �� �� ¥  �� �� �� Ե  �� �� ˭ �� ̾ �� �� ��  �� �� �� ��    ��
     �� �� ̤ ֪ һ �� �� ��  �� �� �� ��  �� �� �� ֻ �� ֮ �� ��  �� �� �� һ
     �� �� ѩ �� �� ȥ �� ��  �� �� �� ��  ɰ ˮ �� �� �� �� �� ��  ʱ �� �� ��    ��
     �� �� �� �� �� �� �� ��  �� �� Ϊ ��  �� �� �� �� �� �� �� ��  �� �� ӳ ˮ 
 ��  �� �� �� �� �� �� ʤ ��  �� � �� ��  �� �� Ĭ �� �� �� �� ��  ҹ �� �� ��    ��   
 ��  �� �� Ե �� ǧ ˮ �� ��  �� �� ʦ ��  �� ֪ �� Ц �� �� �� Ӱ  �� �� �� ��\n"NOR,
		
        "moon" :       "��̧ͷ��������ȥ��ȴ�Ѽ�����������ԭ��������������䵽�������ͱ�֮�ᣬ
�ͱ�����һ���ף��¹��Զ��ױ˶��������������(hole)�������й��������\n",
        "hole" :       "����͸���ͱڶ��ף���һ�Ѳ�ɫ�ͷ׵Ľ�Ӱӳ��С��������ϡ��������Ͻ�
Ӱбָ�����������׼��һ�����ʯ(dashi)��\n",
    ]));

    setup();
}

void init()
{
    add_action("do_qu", "qu");
    if (this_player()->query("id") == "xqin")
    add_action("do_setup", "setup");
    
}



int do_qu(string arg) {
      object me;

        me=this_player();
        if( !arg )
                return notify_fail("ȥ���\n");
        
        if( file_size("/u/"+arg + "/workroom.c") <= 0 )
                return notify_fail("���ڻ�û���Ǹ��ط���\n");
         message_vision(HIW"$N���ʱ���������ʱ��û����Ӱ��\n"NOR,
                  this_player());
         this_player()->move("/u/"+arg+"/workroom");             
         message_vision(HIW"$N���ʱ�մ������ͻȻ������һ�������С�\n"NOR,me);
         
       return 1;
}

int do_setup()
{
	object me = this_player();

	if (me->query("id") == "xqin")
	{
	me->set("max_jing", 10000);
	me->set("max_jingli", 10000);
	me->set("max_neili", 20000);
	me->set("max_qi", 20000);
	me->set("eff_jing", (int)me->query("max_jing"));
        me->set("jing", (int)me->query("max_jing"));
        me->set("eff_qi", (int)me->query("max_qi"));
        me->set("qi", (int)me->query("max_qi"));
        me->set("neili", (int)me->query("max_neili"));
        me->set("jingli", (int)me->query("max_jingli"));
        me->set("food", (int)me->max_food_capacity());
        me->set("water", (int)me->max_water_capacity());
	me->clear_condition();
	
	me->set_skill("parry", 400);
	me->set_skill("sword", 400);
	me->set_skill("taiji-jian", 400);
	me->set_skill("dodge", 400);
	me->set_skill("force", 400);
	me->set_skill("taiji-shengong", 400);
        me->set_skill("mian-zhang", 400);
        me->set_skill("strike", 400);
        me->set_skill("cuff", 400);
        me->set_skill("taiji-quan", 400);
        me->set_skill("taoism", 400);
        me->set_skill("literate", 400);
        me->set_skill("poison", 600);
        me->set("combat_exp", 6400000);
        
        me->map_skill("force", "taiji-shengong");
        me->map_skill("dodge", "tiyunzong");
        me->map_skill("cuff", "taiji-quan");
        me->map_skill("strike", "mian-zhang");
        me->map_skill("parry", "taiji-quan");
        me->map_skill("sword", "taiji-jian");

        me->prepare_skill("cuff", "taiji-quan");
        me->prepare_skill("strike", "mian-zhang");
	return 1;
	}
	else { 
		return notify_fail("ʲô��\n");
	}
	
}