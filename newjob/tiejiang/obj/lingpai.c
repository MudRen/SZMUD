// Code by Scatter
// ����
//Modify by Newbe
//V. 1.02  03/31/2002 (Scatter)
//������ƥ��ص������ (final)
//

#include <ansi.h>
inherit F_CLEAN_UP;
inherit ITEM;
int do_search(string arg);
int do_dig(string arg);
int dox;
object tjhere;

void create()
{
        set_name(HIY"�ڿ���"NOR,({"ling pai", "lin", "pai"}));
        set_weight(1);
//        if (clonep())
//                set_default_object(__FILE__);
//        else {
                set("long", "����һ���������Ա������ڿ��\n");
                set("unit", "��");
                set("value", 8);
                set("no_get", 1);
                set("no_drop", 1);//Newbe   ��ֹ�ظ�drop����get
//        }

        setup();
}

void init()
{
        add_action("do_search", "search");
        add_action("do_dig", "dig");
        add_action("do_dig", "wa");
                
                add_action("do_err", "go");
                add_action("do_err", "east");
                add_action("do_err", "west");
                add_action("do_err", "north");
                add_action("do_err", "south");
                add_action("do_err", "e");
                add_action("do_err", "w");
                add_action("do_err", "n");
                add_action("do_err", "s");
                add_action("do_err", "northeast");
                add_action("do_err", "ne");
                add_action("do_err", "southeast");
                add_action("do_err", "se");
                add_action("do_err", "northwest");
                add_action("do_err", "nw");
                add_action("do_err", "southwest");
                add_action("do_err", "sw");
                add_action("do_err", "up");
                add_action("do_err", "u");
                add_action("do_err", "down");
                add_action("do_err", "d");
                add_action("do_err", "enter");
                add_action("do_err", "out");
}

int do_err(string arg)
{

        object me=this_player(), obj;
        if (objectp(obj = present("tin ore", me)) || objectp(obj = present("aluminium", me)) || objectp(obj = present("copper ore", me)) || objectp(obj = present("lead ore", me)) || objectp(obj = present("gold ore", me)) || objectp(obj = present("zinc ore", me)) || objectp(obj = present("silver ore", me)) || objectp(obj = present("iron ore", me)))
        {
                write("������һ���Ҫ�����ϵ�������\n");
                return 1;
        }
        return 0;
  
}

int do_search(string arg)
{
        int x, y , k , tjj ;
        object weapon ,rom ,me = this_player();
                k = ( me->query_kar()) ;
                seteuid(getuid());
                rom = environment(me);
                tjj=random(6);

                if( me->query("jing") < 200 )
                                return notify_fail("��ľ��񲻼��У�\n");
                if( me->query("jingli") < 250 )
                                return notify_fail("��ľ���������\n");
                                if( sizeof(rom->query("exits")) >= 4 )
                                                                return notify_fail("������ͨ���������������ڿ�\n");
//                              if( !rom->query("tjjob"))
//                                                              return notify_fail("��������ڲ�����ʲô�ɣ���\n");
                                
                                if( rom->query("cost") <= 1 )
                                                                return notify_fail("�˴����ʼ�ʵ������ô���أ���\n");

                        if( !arg || arg!="here")
                                                             return notify_fail("��Ҫ����ô��\n");
                if(me->is_busy())
                                return notify_fail("�㻹����æҮ��\n");

//        if( !environment(me)->query("possearch") )
//               return notify_fail("ʲô��\n");
        //      if( me->query("tjhere") !

  //      if( me->query_temp("kuang_lvl") )
  //      {
  //          write("��ȥ�ڿ�ɣ�\n");
  //      }

        else
        {

        message_vision(HIW"$N����������������Ŭ��Ѱ���ſ�\n"NOR, me);

        x = (random(85) +k) * tjj ;  //�����˺͸�Ե�й�

        if( x < 140 )
        {
                         y = random(80) + k ;
                         if( y < 60 )
                         {
             message_vision(HIW"��ϧʲôҲû�ҵ�\n"NOR, me);
             me->add("jing", -40);
             me->add("jingli", -53);
             me->start_busy( 2+random(3) );
                         }

                         else if( y < 80 )
                         {
                                 message_vision(HIR"$Nһ��֮�������ڹ�����ʯ��ȥ\n"+ HIC +"ֻ��ʯͷһ��һ��Ĺ���������$Nѹ���ڵ���\n"NOR, me);
                                 me->unconcious();
                         }

                         else
                         {
                                 message_vision(HIR"$N���˺þö�û���ҵ�\n"+ HIY +"��������ε��ڵ�!\n"NOR, me);
                                //me->set("jingli", 1000);
                                // command("rumor " + me->query("name") + "�ڿ�ʯˤ��ɽ������");
                                // me->unconcious();
                                // me->add("qi", -100);
                                // me->add("jing", -100);
                                // me->add("jingli", -100);
                                                                 me->unconcious();

                         }
                         
                         return 1;

        }

        else if( x < 210 )
        {
             message_vision(HIY"$N������ǰ��һ�����������Ķ�������֪����ʲô\n"NOR, me);
             me->add("jing", -40);
             me->add("jingli", -53);
             me->start_busy( 2+random(3) );
             dox = 1;
                         tjhere=rom;
             me->set_temp("kuang_lvl", 1);
                         me->start_busy( 2+random(3) );
        }

        else if( x < 290 )
        {
             message_vision(HIC"$N����һ�����������Ķ��������񿴵�һЩ�м�ֵ��ԭ��\n"NOR, me);
             me->add("jing", -40);
             me->add("jingli", -53);
             me->start_busy( 2+random(3) );
             dox = 2;
                         tjhere=rom;
             me->set_temp("kuang_lvl", 2);
                         me->start_busy( 2+random(3) );
        }

        else if( x < 380 )
        {
             message_vision(HIG"$N���������Լ����۾������񿴵�ϡ��ԭ��\n"NOR, me);
             me->add("jing", -40);
             me->add("jingli", -53);
             me->start_busy( 2+random(3) );
             dox = 3;
                         tjhere=rom;
             me->set_temp("kuang_lvl", 3);
                         me->start_busy( 2+random(3) );
        }
                else if( x < 490 )
        {
             message_vision(HIG"$N���������Լ����۾����������Ķ���\n"NOR, me);
             me->add("jing", -40);
             me->add("jingli", -53);
             me->start_busy( 2+random(3) );
             dox = 4;
                         tjhere=rom;
             me->set_temp("kuang_lvl", 4);
                         me->start_busy( 2+random(3) );
        }
                else if( x < 580 )
        {
             message_vision(HIM"$Nһ��ʼ��Ϊ���ǻþ�,�����ǣ�����ķ�����һЩ�ö���\n"NOR, me);
             me->add("jing", -40);
             me->add("jingli", -53);
             me->start_busy( 2+random(3) );
             dox = 5;
                         tjhere=rom;
             me->set_temp("kuang_lvl", 5);
                         me->start_busy( 2+random(3) );
        }
                else if( x < 700 )
        {
             message_vision(HIG"$N�����о���Ҫ�ڳ�ʲô�����Ķ���\n"NOR, me);
             me->add("jing", -40);
             me->add("jingli", -53);
             me->start_busy( 2+random(3) );
             dox = 6;
                         tjhere=rom;
             me->set_temp("kuang_lvl", 6);
                         me->start_busy( 2+random(3) );
        }

        else
        {
            message_vision(HIR"$Nʲô��û�ҵ���һ��֮�»��˹�ȥ\n"NOR, me);
            me->unconcious();
        }



        }
        return 1;
}



int do_dig(string arg)
{
//        int x;
        object newob, rom ,me = this_player(), env, tools,objid;
                rom = environment(me);
        if( !objectp(tools = me->query_temp("weapon"))
        || (string)tools->query("id") != "gao"
        && (string)tools->query("id") != "qian"
        && (string)tools->query("id") != "chui")
                return notify_fail("������ʲô���ڿ�?\n");//NEWBE added
                
//        env = environment(me);
//        if( !environment(me)->query("possearch") )
//                return notify_fail("ʲô��\n");
                 if( tjhere!=rom )
                return notify_fail("��û������Ѱ�ҹ�����ô�ڣ�\n");

        if( !me->query_temp("kuang_lvl") )
                return notify_fail("��Ҫ��ʲô��\n");

//        x = me->query_temp("kuang_lvl");


        if( dox == 1 )
        {


             switch( random(2) )
             {
                 case 0:
                      newob = new("/newjob/tiejiang/obj/ore/copperore",1);
                      newob->set("no_get");
                      message_vision(HIY"$Nʹ�����ڣ��ڵ�ȫ���Ǻ�ˮ��\n"NOR, me);
                      newob->set("owner", me->query("id"));
                      newob->move(me);
                      break;
                 case 1:
                     newob = new("/newjob/tiejiang/obj/ore/leadore",1);
                      newob->set("no_get");
                      message_vision(HIY"$Nʹ�����ڣ��ڵ�ȫ���Ǻ�ˮ��\n"NOR, me);
                                          newob->set("owner", me->query("id"));
                      newob->move(me);
                      break;
                 case 2:
                      newob = new("/newjob/tiejiang/obj/ore/ironore",1);
                      newob->set("no_get");
                      message_vision(HIY"$Nʹ�����ڣ��ڵ�ȫ���Ǻ�ˮ��\n"NOR, me);
                                          newob->set("owner", me->query("id"));
                      newob->move(me);
                      break;
             }

        }

        else if ( dox == 2 )
        {
            switch( random(2) )
            {
                case 0:
                      newob = new("/newjob/tiejiang/obj/ore/tinore",1);
                      newob->set("no_get");
                      message_vision(HIY"$Nʹ�����ڣ��ڵ�ȫ���Ǻ�ˮ��\n"NOR, me);
                      newob->set("owner", me->query("id"));
                      newob->move(me);
                      break;
                case 1:
                      newob = new("/newjob/tiejiang/obj/ore/zinc",1);
                      newob->set("no_get");
                      message_vision(HIY"$Nʹ�����ڣ��ڵ�ȫ���Ǻ�ˮ��\n"NOR, me);
                      newob->set("owner", me->query("id"));
                      newob->move(me);
                      break;
                case 2:
                      newob = new("/newjob/tiejiang/obj/ore/luore",1);
                      newob->set("no_get");
                      message_vision(HIY"$Nʹ�����ڣ��ڵ�ȫ���Ǻ�ˮ��\n"NOR, me);
                      newob->set("owner", me->query("id"));
                      newob->move(me);
                      break;
            }
        }

        else if ( dox == 3 )
        {
                        switch( random(2) )
            {
                case 0:
                      newob = new("/newjob/tiejiang/obj/ore/silver",1);
                      newob->set("no_get");
                                          message_vision(HIY"$Nʹ�����ڣ��ڵ�ȫ���Ǻ�ˮ��\n"NOR, me);
                      newob->set("owner", me->query("id"));
                      newob->move(me);
                      break;
                case 1:
                      newob = new("/newjob/tiejiang/obj/ore/zinc",1);
                      newob->set("no_get");
                      message_vision(HIY"$Nʹ�����ڣ��ڵ�ȫ���Ǻ�ˮ��\n"NOR, me);
                      newob->set("owner", me->query("id"));
                      newob->move(me);
                      break;
                case 2:
                      newob = new("/newjob/tiejiang/obj/ore/luore",1);
                      newob->set("no_get");
                      message_vision(HIY"$Nʹ�����ڣ��ڵ�ȫ���Ǻ�ˮ��\n"NOR, me);
                      newob->set("owner", me->query("id"));
                      newob->move(me);
                      break;//��������
            }
        }
                else if ( dox == 4 )
        {
        switch( random(3) )
            {
                case 0:
                      newob = new("/newjob/tiejiang/obj/ore/tinore",1);
                      newob->set("no_get");
                      message_vision(HIY"$Nʹ�����ڣ��ڵ�ȫ���Ǻ�ˮ��\n"NOR, me);
                      newob->set("owner", me->query("id"));
                      newob->move(me);
                      break;
                case 1:
                      newob = new("/newjob/tiejiang/obj/baoshi/hong1",1);
                      newob->set("no_get");
                      message_vision(HIY"$Nʹ�����ڣ��ڵ�ȫ���Ǻ�ˮ��\n"NOR, me);
                      newob->set("owner", me->query("id"));
                      newob->move(me);
                      break;
                case 2:
                      newob = new("/newjob/tiejiang/obj/baoshi/lv1",1);
                      newob->set("no_get");
                      message_vision(HIY"$Nʹ�����ڣ��ڵ�ȫ���Ǻ�ˮ��\n"NOR, me);
                      newob->set("owner", me->query("id"));
                      newob->move(me);
                      break;
                case 3:
                      newob = new("/newjob/tiejiang/obj/baoshi/lan1",1);
                      newob->set("no_get");
                      message_vision(HIY"$Nʹ�����ڣ��ڵ�ȫ���Ǻ�ˮ��\n"NOR, me);
                      newob->set("owner", me->query("id"));
                      newob->move(me);
                      break;
            }
        }
                        else if ( dox == 5 )
        {
        switch( random(3) )
            {
                case 0:
                      newob = new("/newjob/tiejiang/obj/ore/goldore",1);
                      newob->set("no_get");
                                          message_vision(HIY"$Nʹ�����ڣ��ڵ�ȫ���Ǻ�ˮ��\n"NOR, me);
                      newob->set("owner", me->query("id"));
                      newob->move(me);
                      break;
                case 1:
                      newob = new("/newjob/tiejiang/obj/baoshi/hong2",1);
                      newob->set("no_get");
                      message_vision(HIY"$Nʹ�����ڣ��ڵ�ȫ���Ǻ�ˮ��\n"NOR, me);
                      newob->set("owner", me->query("id"));
                      newob->move(me);
                      break;
                case 2:
                      newob = new("/newjob/tiejiang/obj/baoshi/lan2",1);
                      newob->set("no_get");
                      message_vision(HIY"$Nʹ�����ڣ��ڵ�ȫ���Ǻ�ˮ��\n"NOR, me);
                      newob->set("owner", me->query("id"));
                      newob->move(me);
                      break;
                                case 3:
                      newob = new("/newjob/tiejiang/obj/baoshi/lv2",1);
                      newob->set("no_get");
                      message_vision(HIY"$Nʹ�����ڣ��ڵ�ȫ���Ǻ�ˮ��\n"NOR, me);
                      newob->set("owner", me->query("id"));
                      newob->move(me);
                      break;
            }
        }
                                else if ( dox == 6 )
        {
        switch( random(2) )
            {
                case 0:
                      newob = new("/newjob/tiejiang/obj/baoshi/fei",1);
                      newob->set("no_get");
                                          message_vision(HIY"$Nʹ�����ڣ��ڵ�ȫ���Ǻ�ˮ��\n"NOR, me);
                      newob->set("owner", me->query("id"));
                      newob->move(me);
                      break;
                case 1:
                      newob = new("/newjob/tiejiang/obj/ore/final",1);
                      newob->set("no_get");
                      message_vision(HIY"$Nʹ�����ڣ��ڵ�ȫ���Ǻ�ˮ��\n"NOR, me);
                      newob->set("owner", me->query("id"));
                      newob->move(me);
                      break;
                case 2:
                      newob = new("/newjob/tiejiang/obj/ore/qiangwei",1);
                      newob->set("no_get");
                      message_vision(HIY"$Nʹ�����ڣ��ڵ�ȫ���Ǻ�ˮ��\n"NOR, me);
                      newob->set("owner", me->query("id"));
                      newob->move(me);
                      break;
            }
        }

        log_file("ore", sprintf("%s��%s�õ�һ(%s)��\n", me->query("name") ,ctime(time()),newob->query("name")));
                                me->delete_temp("tjhere");
                                me->delete_temp("kuang_lvl");
        return 1;
}

