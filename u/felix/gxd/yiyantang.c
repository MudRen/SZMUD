// Code of ShenZhou
// Room: /beijing/yiyantang.c

#include "ansi.h"
inherit ROOM;

void create()
{
    set("short", HIB"һ����"NOR);
    set("long", @LONG
�����������������һ���ã�����һ�ң����޷ֺš�����Ļ��ã���ǮҲ��
���ˡ�����ν�����ʵ�Ů������ޡ�����ǽ����һ�Ż��� (shelf)���������ԣ�
һ�����ݵļһﵹ��̫ʦ���ϣ�����һ֧�����ĺ��̹ܣ�һ�߻����Ŷ����ȣ���
�ﻹ�ߺ���С�����������������ƹ���ˡ�������һ���衣һ�������ſ�ڹ�̨
�ϴ����̨������һ�ŷ��Ƶļ�Ŀ��(sign)��
LONG
    );

    set("item_desc", ([
            "shelf" : "�����Ͽյ����ģ�������ʲô������\n",
            "sign" : "
		ͯ������ �Բ�����


	������(slz)��\t              ��ʮ�㹱�׶�
	������(ptz)��\t            ��ʮ��㹱�׶�
	һ����������(death)��\t      ��ʮ�㹱�׶�
	�츣��(tianfu)��\t           һ�ٵ㹱�׶�
	һ��������ò(rongmao)��\t    ���ٵ㹱�׶�
	һ�����츣Ե(fuyuan)��\t ������ʮ�㹱�׶�
	һ�����(bili)��\t           �˰ٵ㹱�׶�
	һ������(wuxing)��\t         �˰ٵ㹱�׶�
	һ�����(gengu)��\t          һǧ�㹱�׶�
	һ����(shenfa)��\t     һǧ���ٵ㹱�׶�
	������(pldan)��\t            һǧ�㹱�׶�
	������һ��Ȩ��(9yin1)��\t    �˰ٵ㹱�׶�
	�����ڶ���Ȩ��(9yin2)��\tһǧ��ٵ㹱�׶�
	����������Ȩ��(9yin3)��\t    ��ǧ�㹱�׶�
	
	���׶ȵĶһ�������
	exchange xxx  ˵����xxx Ϊ�����ڵ�����
	�磺�һ� ������(ptz)���� exchange ptz\n",
    ]));

    set("exits", ([
            "south" : __DIR__"changanjie_w",
    ]));

	set("objects", ([
		"/d/beijing/npc/yythuoji" : 1,
	]));

    set("no_fight", "1");
    set("no_steal", "1");
    set("cost", 0);
    //set("day_shop", 1);
    setup();
}

void init()
{
    add_action( "exchange", "exchange" );
}

int exchange( string arg )
{
    object me = this_player();   
    object obj; 
    int gxd=0, temp;    
    if ( !arg )
        return notify_fail( "��Ҫ�ù��׶Ȼ�ʲô��\n" );
    gxd = me->query( "shenzhou/pts" );
    if ( !gxd )
        return notify_fail( "�������û�й��ס�\n" );   
    switch( arg )
    {
    case "slz":
        if ( gxd > 19 )
        {
            obj = new ( "/clone/gongxian/sheli-zi" );
            obj->move( me );
            gxd = gxd - 20;
            me->set( "shenzhou/pts", gxd );
            tell_object( me, "��õ�һ�������ӡ�\n" );
            log_file("static/exchange", me->name() + "(" + me->query("id") + ") exchange " + arg + " at " + ctime(time()) + "\n");      
            return 1;
        }
        break;
    case "ptz":
        if ( gxd > 24 )
        {
            obj = new ( "/clone/gongxian/puti-zi" );
            obj->move( me );
            gxd = gxd - 25;
            me->set( "shenzhou/pts", gxd );
            tell_object( me, "��õ�һ�������ӡ�\n" );
            log_file("static/exchange", me->name() + "(" + me->query("id") + ") exchange " + arg + " at " + ctime(time()) + "\n");      
            return 1;
        }    
        break;
    case "tianfu":
        if ( gxd > 99 )
        {
            obj = new ( "/clone/gongxian/tianfu" );
            obj->move( me );
            gxd = gxd - 100;
            me->set( "shenzhou/pts", gxd );
            shout( HIM "��ҥ�ԡ�ĳ�ˣ���˵"HIC + me->query( "name" ) + HIM"�����������й��������һö�츣����\n" NOR ); 
            write( HIM "��ҥ�ԡ�ĳ�ˣ���˵"HIC + me->query( "name" ) + HIM"�����������й��������һö�츣����\n" NOR );             
            log_file("static/exchange", me->name() + "(" + me->query("id") + ") exchange " + arg + " at " + ctime(time()) + "\n");      
            return 1;
        }     
        break;           
    case "pldan":
        if ( gxd > 999 )
        {
            obj = new ( "/clone/gongxian/pldan" );
            obj->move( me );
            gxd = gxd - 1000;
            me->set( "shenzhou/pts", gxd );
            shout( HIM "��ҥ�ԡ�ĳ�ˣ���˵"HIC + me->query( "name" ) + HIM"�����ŵ���أ�����ͨ�����ڣ��õ���һö��������\n" NOR ); 
            write( HIM "��ҥ�ԡ�ĳ�ˣ���˵"HIC + me->query( "name" ) + HIM"�����ŵ���أ�����ͨ�����ڣ��õ���һö��������\n" NOR );             
            log_file("static/exchange", me->name() + "(" + me->query("id") + ") exchange " + arg + " at " + ctime(time()) + "\n");      
            return 1;
        }     
        break;    
    case "bili":
        if ( gxd > 799 )
        {
            gxd = gxd - 800;
            me->set( "shenzhou/pts", gxd );
            me->add( "str", 1 );
            shout( HIM "��ҥ�ԡ�ĳ�ˣ���˵"HIC + me->query( "name" ) + HIM"·�����ɣ��ɽ����У��Ӵ˱������ǡ�\n" NOR ); 
            write( HIM "��ҥ�ԡ�ĳ�ˣ���˵"HIC + me->query( "name" ) + HIM"·�����ɣ��ɽ����У��Ӵ˱������ǡ�\n" NOR );             
            log_file("static/exchange", me->name() + "(" + me->query("id") + ") exchange " + arg + " at " + ctime(time()) + "\n");      
            return 1;
        }     
        break;        
    case "wuxing":
        if ( gxd > 799 )
        {
            gxd = gxd - 800;
            me->set( "shenzhou/pts", gxd );
            me->add( "int", 1 );
            shout( HIM "��ҥ�ԡ�ĳ�ˣ���˵"HIC + me->query( "name" ) + HIM"��Ϊ���ݳ�ı���ߣ�ʹ��ѧʶ��Ϊͻ���ͽ���\n" NOR ); 
            write( HIM "��ҥ�ԡ�ĳ�ˣ���˵"HIC + me->query( "name" ) + HIM"��Ϊ���ݳ�ı���ߣ�ʹ��ѧʶ��Ϊͻ���ͽ���\n" NOR );             
  
            log_file("static/exchange", me->name() + "(" + me->query("id") + ") exchange " + arg + " at " + ctime(time()) + "\n");      
  
            return 1;
        }     
        break;
    case "gengu":
        if ( gxd > 999 )
        {
            gxd = gxd - 1000;
            me->set( "shenzhou/pts", gxd );
            me->add( "con", 1 );
            shout( HIM "��ҥ�ԡ�ĳ�ˣ���˵"HIC + me->query( "name" ) + HIM"�����������й����������ڴ��������������\n" NOR ); 
            write( HIM "��ҥ�ԡ�ĳ�ˣ���˵"HIC + me->query( "name" ) + HIM"�����������й����������ڴ��������������\n" NOR );             
            log_file("static/exchange", me->name() + "(" + me->query("id") + ") exchange " + arg + " at " + ctime(time()) + "\n");      
            return 1;
        }     
        break;
   case "shenfa":
        if ( gxd > 1199 )
        {
            gxd = gxd - 1200;
            me->set( "shenzhou/pts", gxd );
            me->add( "dex", 1 );
            shout( HIM "��ҥ�ԡ�ĳ�ˣ���˵"HIC + me->query( "name" ) + HIM"����������״����ؾ���ϰ��һ��߳��Ṧ��\n" NOR ); 
            write( HIM "��ҥ�ԡ�ĳ�ˣ���˵"HIC + me->query( "name" ) + HIM"����������״����ؾ���ϰ��һ��߳��Ṧ��\n" NOR );             
            log_file("static/exchange", me->name() + "(" + me->query("id") + ") exchange " + arg + " at " + ctime(time()) + "\n");      
            return 1;
        }     
        break;
    case "roumao":
        if ( gxd > 199 )
        {
            /*if ( temp = me->query( "per" ) > 29 (
                return notify_fail( "���Ѿ��㹻���ˡ�\n" );*/
            gxd = gxd - 200;
            me->set( "shenzhou/pts", gxd );
            me->add( "per", 1 );
            shout( HIM "��ҥ�ԡ�ĳ�ˣ���˵"HIC + me->query( "name" ) + HIM"����Ϊ�ж�������ר˾��ò�����ɣ��״��������ഺ֮����\n" NOR ); 
            write( HIM "��ҥ�ԡ�ĳ�ˣ���˵"HIC + me->query( "name" ) + HIM"����Ϊ�ж�������ר˾��ò�����ɣ��״��������ഺ֮����\n" NOR );             
            log_file("static/exchange", me->name() + "(" + me->query("id") + ") exchange " + arg + " at " + ctime(time()) + "\n");      
            return 1;
        }     
        break;                                
    case "fuyuan":
        if ( gxd > 249 )
        {
            /*if ( temp = me->query( "per" ) > 29 (
                return notify_fail( "���Ѿ��㹻���ˡ�\n" );*/
            gxd = gxd - 250;
            me->set( "shenzhou/pts", gxd );
            me->add( "kar", 1 );
            shout( HIM "��ҥ�ԡ�ĳ�ˣ���˵"HIC + me->query( "name" ) + HIM"���������񣬹ʶ�����Ϊ�ѣ���������Ϊ�󸣴���������\n" NOR ); 
            write( HIM "��ҥ�ԡ�ĳ�ˣ���˵"HIC + me->query( "name" ) + HIM"���������񣬹ʶ�����Ϊ�ѣ���������Ϊ�󸣴���������\n" NOR );             
            log_file("static/exchange", me->name() + "(" + me->query("id") + ") exchange " + arg + " at " + ctime(time()) + "\n");      
            return 1;
        }     
        break;    
    case "death":
        if ( gxd > 79 )
        {
            /*if ( temp = me->query( "per" ) > 29 (
                return notify_fail( "���Ѿ��㹻���ˡ�\n" );*/
            gxd = gxd - 80;
            me->set( "shenzhou/pts", gxd );
            me->add( "death_times", 1 );
            shout( HIM "��ҥ�ԡ�ĳ�ˣ���˵"HIC + me->query( "name" ) + HIM"���ظ�ڤ����Ϊ���ϼѱ����Ӷ��޵þ�����˫����ħ����󷨡�\n" NOR ); 
            write( HIM "��ҥ�ԡ�ĳ�ˣ���˵"HIC + me->query( "name" ) + HIM"���ظ�ڤ����Ϊ���ϼѱ����Ӷ��޵þ�����˫����ħ����󷨡�\n" NOR );             
            log_file("static/exchange", me->name() + "(" + me->query("id") + ") exchange " + arg + " at " + ctime(time()) + "\n");      
            return 1;
        }     
        break;       
    case "9yin1":
        if ( gxd > 799 )
        {
            /*if ( temp = me->query( "per" ) > 29 (
                return notify_fail( "���Ѿ��㹻���ˡ�\n" );*/
            gxd = gxd - 800;
            me->set( "shenzhou/pts", gxd );
            me->set( "9yin", "granted1" );
            shout( HIM "��ҥ�ԡ�ĳ�ˣ���˵"HIC + me->query( "name" ) + HIM"���������̶�õ��˾����澭��һ����˵��������Ϊ��ָ·��\n" NOR ); 
            write( HIM "��ҥ�ԡ�ĳ�ˣ���˵"HIC + me->query( "name" ) + HIM"���������̶�õ��˾����澭��һ����˵��������Ϊ��ָ·��\n" NOR );             
            log_file("static/exchange", me->name() + "(" + me->query("id") + ") exchange " + arg + " at " + ctime(time()) + "\n");      
            return 1;
        }     
        break;     
    case "9yin2":
        if ( gxd > 1499 )
        {
            gxd = gxd - 1500;
            me->set( "shenzhou/pts", gxd );
            me->set( "9yin", "granted2" );
            shout( HIM "��ҥ�ԡ�ĳ�ˣ���˵"HIC + me->query( "name" ) + HIM"���ܻ��ס����������������õ��˾����澭�ڶ���\n" NOR ); 
            write( HIM "��ҥ�ԡ�ĳ�ˣ���˵"HIC + me->query( "name" ) + HIM"���ܻ��ס����������������õ��˾����澭�ڶ���\n" NOR );             
            log_file("static/exchange", me->name() + "(" + me->query("id") + ") exchange " + arg + " at " + ctime(time()) + "\n");      
            return 1;
        }     
        break;     
    case "9yin3":
        if ( gxd > 2999 )
        {
            gxd = gxd - 3000;
            me->set( "shenzhou/pts", gxd );
            me->set( "9yin", "granted3" );
            shout( HIM "��ҥ�ԡ�ĳ�ˣ���˵"HIC + me->query( "name" ) + HIM"�����������ɽ磬������ϰ���������������񹦵Ļ��ᡣ\n" NOR ); 
            write( HIM "��ҥ�ԡ�ĳ�ˣ���˵"HIC + me->query( "name" ) + HIM"�����������ɽ磬������ϰ���������������񹦵Ļ��ᡣ\n" NOR );             
            log_file("static/exchange", me->name() + "(" + me->query("id") + ") exchange " + arg + " at " + ctime(time()) + "\n");      
            return 1;
        }     
        break;  
    default:                           
        return notify_fail( "��Ҫ��ʲô��\n" );
    }
    return notify_fail( "��Ĺ��׶Ȳ����������\n" );
}
