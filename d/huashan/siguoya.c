// Code of ShenZhou
// ��ɽ˼����
// qfy 26/6/1996 

#include <ansi.h>

inherit ROOM;

int do_say(string arg);
void create()
{
        set("short", "˼����");
	set("long", @LONG
���ǻ�ɽ��˼���¡�Σ�����и�ɽ�����ǻ�ɽ���������ӷ��������
�ܷ�֮�������Ϲ�ͺͺ�Ĵ�ݲ���������һ����ľ����Σ�����������ഫ
����Ů�����ϵ�һ�����飬���껪ɽ�ɵ���ʦ�Դ�Σ��Ϊ�ͷ�����֮����
��Ҫ�Ǳ��һ���޲���ľ���޳������ܷ��ĵ��������˼��֮ʱ������
Ϊ�������ţ��������͡�
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  	"southdown" : __DIR__"shanlu2",
  	"enter" : __DIR__"shandong",
]));

	set("cost", 3);
        set("outdoors", "huashan" );
        set("fjing", 1);
        setup();
}

void init()
{
	add_action("do_say", "say");
}	

int do_say(string arg)
{  
	string name;
	object me = this_player();
	
	if( !arg || arg=="" ) return 0;
	
	if (arg != "������" ) return 0;
	
	if( !me->query_temp("marks/��") ) 
	{
	  if (random(30) == 5 )
	  {
	  message_vision("ͻȻ$N������һ����̾�����ѵ����Ͼ�Ȼ������֪����ĳ�����֡���\n", me);
          message_vision("$N�ع�ͷ������ɽ����վ��һ�������������ߣ����������������ֽ��\n", me);
          me->set_temp("marks/��", 1);
	  if ( me->query("shen") >= 10000 ) {      
	        message("vision","�������"+me->name()+"������˵�˼��仰��˵�ձ�ƮȻ��ɽ��\n", 
	                environment(me), ({me})); 	
		write( "�����������˵����������������ǰ����һ�������ؽ����۽�����\n");
		write( "�ųơ���ħ�����߱���������һ���ֶ�����Ϊ��һ�ܶ����ã�һ��\n");
		write( "�żš�������һ���������񽣡���ڣ�����غ���Ⱥ�����֣�������\n");
		write( "�������౯�򣡾��š���ڣ�������ڵ���λ��̩ɽ����ʯ���Ĵ��\n");
		write( "�⣬������֡����ڵ�������Ĵ���⣬�������֪��ϣ������Ѱ��\n");
		write( "�������츣���֡�\n");
		write( "������˵�գ���ƮȻ��ɽ��\n");
		return 1;
          	}
          else 	{	
          	message_vision( "������˵�գ��ֶ�$Nһ����̾����ƮȻ��ɽ��ȥ��\n", me );
          	return 1;
          	}	
          }
          else	
          	{
          	message_vision(CYN"$N˵����������\n"NOR,this_player());
          	return 1;
          	}
	}
	
	if( arg == "������" && me->query_temp("marks/��") ) {
      write( "�����ͻȻ���˳���˵���������Ǽ������������𣿻�����ȥ������������\n");
      return 1;
	}  
	return 1;
}		 
