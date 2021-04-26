#include <ansi.h>
inherit ROOM;
string look_jia();
void create()
{
             set("short", HIY"����С��"NOR);
        set("long", @LONG
����̫�������ĵط�.����ʮ�ּ�ª��ǽ����һ������(jia).
LONG);
        set("exits", ([
      "rob":"/u/rob/workroom", 
                  "down" : "/d/city/guangchang",
                   "north"  : "/u/taiyang/fightroom", 
                     "hs"  : "/d/huashan/buwei1", 
                       "qz"  : "/d/zhongnan/taijie2", 
                      "yz"  : "d/city/kedian", 
                      "ts"  : "/d/taishan/fengchan", 
                     "bt"  : "/d/baituo/btyard", 
                      "sl"  : "/d/shaolin/guangchang1", 
                      "wn"  : "/d/wudang/sanqingdian", 
                      "sn"  : "/d/shenlong/tingkou", 
                      "gb"  : "/d/gaibang/undertre", 
                      "xx"  : "/d/xingxiu/xxh2", 
                      "em"  : "/d/emei/hz_guangchang", 
                      "xs"  : "/d/xueshan/guangchang", 
                      "kl"  : "/d/kunlun/sanshengtang",                       
                      "bj"  : "/d/beijing/changanjie", 
                      "xi"  : "/d/xixia/dawu", 
                      "gy"  : "/d/taihu/qianyuan", 
                      "dl"  : "/d/dali/wangfu1", 
                      "hz"  : "/d/hangzhou/kedian", 
                      "gm"  : "/d/gumu/dating", 
                     "wr"  : "/d/wizard/wizard_room", 
                      "th"  : "/d/taohua/jingshe", 
"afei":"/u/afei/workroom",
         "west" : "/u/taiyang/chufang",
]));
              set("objects", ([ 
                      __DIR__"xiaoqie" : 1, 
      ])); 
  set("no_fight", "1"); 
       set("item_desc", ([
                "jia": (: look_jia :),
]));
                   call_other("/clone/board/taiyang_b", "???");   
setup(); 
}

void init()
{
add_action("do_get", "get");
}
int do_get(string arg)
{
        object weapon, me=this_player();
        string type;
        if(!arg) return 0;
        if(me->is_busy()) return 0;
        if (sscanf(arg, "%s from jia", type) != 1) return 0;
       if (!wizardp(me)) return 0;

switch(type)
{
case"jian": weapon = new("/clone/weapon/qinggang-jian");
break;
case"dao": weapon = new("/clone/weapon/fumo-dao");
break;
case"stick": weapon = new("/u/taiyang/obj/stick.c");
break;
case"staff": weapon = new("/clone/weapon/gangzhang");
break;
case"whip": weapon = new("/u/taiyang/whip");
break;
case"hama": weapon = new("/u/athena/obj/hama");
break;
case"xiao": weapon = new("/u/mxj/tongxiao");
break;
case"qi": weapon = new("/clone/wiz/mihun");
break;
case"armor": weapon = new("/clone/armor/jinshe-beixin");
break;
case"lingzhi": weapon = new("/u/taiyang/obj/lingzhi");  
break;
      case"ganlu": weapon = new("clone/wiz/ganlu");  
   break;
      case"guo": weapon = new("clone/wiz/guo");  
break;
      case"zhu": weapon = new("/clone/wiz/beauty"); 
      break; 
case"money": weapon = new("/clone/money/thousand-cash");
break;
      case"jiuzhuan": weapon = new("/clone/wiz/jiuzhuan"); 
break;
case"gu": weapon = new("/u/keny/obj/gu"); 
break;
      case"baojian": weapon = new("/u/taiyang/baojian.c"); 
      break; 
default:        return notify_fail("�Ҳ���"+type+"\n");
}
        if(weapon->move(me)) {
      message_vision("$N�ӱ�������ȡ��һ"+weapon->query("unit")+weapon->name()+"��\n", me);
  } else {
 destruct(weapon);
}
return 1;
}
string look_jia()
{
       string msg;
        msg = " "HIC" ����ָ�� "NOR" get "HIR"(��Ʒ)"NOR" from jia \n";
        msg+= ""HIC"---------------------------------------------------"NOR" \n";
        msg+= ""HIY"��"NOR"(jian)��"HIR"��"NOR"(dao),"GRN"��"NOR"(stick)��"HIG"ͭ��"NOR"(xiao),"CYN"��"NOR"(staff),"YEL"��"NOR"(whip) \n";
        msg+= ""HIC"����"NOR"(armor)��"HIY"Ǯ"NOR"(money)��"MAG"�Ի���"NOR"(qi)��"HIC"���"NOR"(hama)��\n";
        msg+= ""HIC"---------------------------------------------------"NOR" \n";
        return msg;
}
