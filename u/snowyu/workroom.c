//workoom
#include <ansi.h>
#include <room.h>
inherit ROOM;
void reset();
void create()
{
    set("short","��ڷ���"NOR);
set("long", "����һ����ڵķ��䣬ֻ��һ�źܴ����ӣ��������沼���˻ҳ���
"
           
          );
        set("item_desc", ([
                "ji"   : "���������ʱ�մ����ȥ(qu)�����ʦ�İ칫�ҡ�\n"NOR,]));
        
        set("valid_startroom",1);
        set("exits", ([
      "snowlf" : "u/snowlf/workroom",
        "kd" : "/d/city/kedian",
        "kl" : "/d/kunlun/sanshengtang",
        "dl" : "/d/dali/wangfu1",
        "hs" : "/d/huashan/pianting",
        "wz" : "/d/wizard/wizard_room",
        "em" : "/d/emei/hz_guangchang",
        "xs" : "/d/xueshan/guangchang",
        "bt" : "/d/xingxiu/btyard",
        "xa" : "/d/xixia/dawu",
        "qz" : "/d/zhongnan/dadian",
        "sl" : "/d/shaolin/guangchang1",
        "xx" : "/d/xingxiu/xxh2",
        "up" : "/u/snowyu/yangtai",
        "gb" : "/d/gaibang/gbxiaowu",
        "mj" : "/d/mingjiao/damen",
        "gm" : "/d/zhongnan/gumu",
        "wg" : "/d/wudang/xiaoyuan",
        "th" : "/d/taohua/hyjuchu",
        "gy" : "/d/taihu/shufang",
                ]));
          setup();
          call_other("/clone/board/snowyu_b", "???");
}
void init()
{
        object me = this_player();
        if( wizardp(me) && getuid(me)!="snowyu ")
                message("vision", me->name()+"���˹�����\n", environment(me), ({me}));

        
        
        add_action("do_qu","qu");
        add_action("look_paper","look");

}

int do_qu(string arg) {
      object me;
      me=this_player();
        if( !arg )
                return notify_fail("ȥ���\n");
        
        if( file_size("/u/"+arg + "/workroom.c") <= 0 )
                return notify_fail("���ڻ�û���Ǹ��ط���\n");
         message_vision(HIW"$N����ʱ�մ��������ʱ��û����Ӱ��\n"NOR,
                  this_player());
         this_player()->move("/u/"+arg+"/workroom");             
         message_vision(HIW"$N���ʱ�մ������ͻȻ������һ�������С�\n"NOR,me);
         
       return 1;
}
int look_paper(string arg)
{
	if( !arg || arg!="paper" ) return 0;

	write(HIY"                               ��ɫ��˵��\n"NOR);
	write("Black esc[30m BLK       "+BLK"����������"NOR+" ; Red esc[31m RED       "+RED"����������\n"NOR);
	write("Green esc[32m GRN       "+GRN"����������"NOR+" ; Yellow esc[33m YEL    "+YEL"����������\n"NOR);
	write("Blue esc[34m BLU        "+BLU"����������"NOR+" ; Magenta esc[35m MAG   "+MAG"����������\n"NOR);
	write("Cyan esc[36m  CYN       "+CYN"����������"NOR+" ; White esc[37m WHT     "+WHT"����������\n\n"NOR);

	write("Red esc[1;31m HIR       "+HIR"����������"NOR+" ; Green esc[1;32m HIG   "+HIG"����������\n"NOR);
	write("Yellow esc[1;33m HIY    "+HIY"����������"NOR+" ; Blue esc[1;34m HIB    "+HIB"����������\n"NOR);
	write("Magenta esc[1;35m HIM   "+HIM"����������"NOR+" ; Cyan esc[1;36m HIC    "+HIC"����������\n"NOR);
	write("White esc[1;37m HIW     "+HIW"����������\n\n"NOR);

	write("Red esc[42;1m HBRED     "+HBRED"����������"NOR+" ; Green esc[42;1m HBGRN "+HBGRN"����������\n"NOR);
	write("Yellow esc[43;1m HBYEL  "+HBYEL"����������"NOR+" ; Blue esc[44;1m HBBLU  "+HBBLU"����������\n"NOR);
	write("Magenta esc[45;1m HBMAG "+HBMAG"����������"NOR+" ; Cyan esc[46;1m HBCYN  "+HBCYN"����������\n"NOR);
	write("White esc[47;1m HBWHT   "+HBWHT"����������\n\n"NOR);

	write("Black esc[40m BBLK      "+BBLK"����������"NOR+" ; Red esc[41m BRED      "+BRED"����������\n"NOR);
	write("Green esc[42m BGRN      "+BGRN"����������"NOR+" ; Yellow esc[43m BYEL   "+BYEL"����������\n"NOR);
	write("Blue esc[44m BBLU       "+BBLU"����������"NOR+" ; Magenta esc[45m BMAG  "+BMAG"����������\n"NOR);
	write("Cyan esc[46m BCYN       "+BCYN"����������"NOR+" ; White esc[47m BCYN    "+BCYN"����������\n\n"NOR);

	write("Normal esc[2;37;0m NOR   "+NOR"����������\n"NOR);
return 1;
}
/*
int valid_leave(object me, string dir)
{
        if ( !wizardp(me))
                return notify_fail("��Ϊ������,�޷��뿪���� ��\n");
        return ::valid_leave(me, dir);
}
*/
