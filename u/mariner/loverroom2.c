
#include <room.h>
#include <ansi.h>
 
inherit ROOM;

int playing = 0; 
 
void reset();

string *song;

string *zshyn = ({
    
HIG"    ���ٻ����� \n\n"NOR,                             

HIG"    ���������� ��Ҫ������ \n"NOR,
HIG"    ֱ���о�������� �������µĺۼ�\n"NOR,
HIG"    ֱ���϶�������� \n"NOR,
HIG"    ֱ��ʧȥ���� Ϊ���� ��Ը�� \n"NOR,
HIG"    ��Ҳ���ܶ� ҲҪ������ \n"NOR,
HIG"    ֱ���о���ķ��� ���˰�ѩ�ĺۼ� \n"NOR,
HIG"    ֱ�����߱��ģ�� \n"NOR,
HIG"    ֱ�����ܺ��� ��������Ӱ���� \n"NOR,
HIG"    ��� ȫ������Ҳ���Է��� \n"NOR,
HIG"    ���ٻ�����ֵ����ȥ��ϧ ���������� \n"NOR,
HIG"    �����������漣 \n"NOR,

HIG"    Ҳ�� ȫ������Ҳ�������� \n"NOR,
HIG"    ���ǲ�Ը��ʧȥ�����Ϣ \n"NOR,
HIG"    �����ĵ��� ���ܼǵ������� \n"NOR,

HIG"    ���Ǻò����� �������ɼ� \n"NOR,
HIG"    ����ʱ��̫�� �������㿴��ϸ\n"NOR,
HIG"    ����ʱ��̫�� \n"NOR,

HIG"    ��ҹ����ʧȥ�� \n"NOR,
HIG"    �޲���һҹ֮���ͷ �������� \n"NOR,

HIG"    ��� ȫ������Ҳ���Է��� \n"NOR,
HIG"    ���ٻ�����ֵ����ȥ��ϧ \n"NOR,
HIG"    ���������� �����������漣 \n"NOR,

HIG"    Ҳ�� ȫ������Ҳ�������� \n"NOR,
HIG"    ���ǲ�Ը��ʧȥ�����Ϣ \n"NOR,
HIG"    �����ĵ��� ���ܼǵ�������\n"NOR
});

string *woman = ({    
HIG"    When you're in love with a beautiful woman�� \n"NOR,
HIG"    It's hard  \n"NOR,
HIG"    When you're in love with a beautiful woman \n"NOR,
HIG"    You know it's hard  \n"NOR,
HIG"    Everybody wants her,��Everybody loves her   \n"NOR,
HIG"    Everybody wants to take your baby home \n"NOR,
    
HIG"    When you're in love with a beautiful woman�� \n"NOR,
HIG"    You watch your friends \n"NOR,
HIG"    When you're in love with a beautiful woman�� \n"NOR,
HIG"    It never ends\n"NOR,
HIG"    you know that is crazy\n"NOR,
HIG"    you want to trust her\n"NOR,
HIG"    there is somebody hangs up when you answer the phone\n"NOR,

HIG"    When you're in love with a beautiful woman�� \n"NOR,
HIG"    You got it alone  \n"NOR,
HIG"    Maybe just an ego problem \n"NOR,    
HIG"    Problem is I've been fooled before  \n"NOR,
HIG"    But fair weather friends and faint hearted lovers  \n"NOR,
HIG"    And everytime it happens��It just convinces me more  \n"NOR,
HIG"    When you're in love with a beautiful woman�� \n"NOR,
HIG"    You watch her eyes  \n"NOR,
HIG"    When you're in love with a beautiful woman�� \n"NOR,
HIG"    You look for lies  \n"NOR,
HIG"    Everybody tempts her��\n"NOR,
HIG"    Everybody tells her  \n"NOR,
HIG"    When you're in love with a beautiful woman�� \n"NOR,
HIG"    You got it alone  \n"NOR
});

string *qfdy = ({
        
CYN"    ��ǵ���\n\n"NOR,
    
CYN"    �������ǳ��μ���  \n"NOR,
CYN"    һ˫���˵��۾�  \n"NOR,
CYN"    �����Ժ���  �����Ӱ  ��ɢ��ȥ  \n"NOR,
CYN"    �����˫�ָо�������� \n"NOR,
CYN"    ����е�͸������\n"NOR,
CYN"    �������  ������ϧ  \n"NOR,
CYN"    ��������ί��  �һ�����\n"NOR,
CYN"    ֻ�����Լ��ᰮ���� \n"NOR,
CYN"    �������Լ�����̫�� \n"NOR,
CYN"    ����ûʲô�ܹ�����  \n"NOR,
CYN"    ����Ҳ��Ҫ�ܴ������ \n"NOR,
CYN"    ֻ�����Լ��ᰮ���� \n"NOR,
CYN"    ����������鲻�Խ� \n"NOR,
CYN"    ����ֻ���Լ������Լ� \n"NOR,
CYN"    ������������ǵ��� \n\n"NOR,

CYN"    ʲôԭ��  �Ҿ�Ȼ�ֻ������� \n"NOR,
CYN"    �������Ĳ�Ը��  \n"NOR,
CYN"    ���������밮������\n"NOR,
CYN"    ֻ�����Լ��ᰮ���� \n"NOR,
CYN"    �������Լ�����̫�� \n"NOR,
CYN"    ����ûʲô�ܹ�����  \n"NOR,
CYN"    ����Ҳ��Ҫ�ܴ������ \n"NOR,
CYN"    ֻ�����Լ��ᰮ���� \n"NOR,
CYN"    ����������鲻�Խ� \n"NOR,
CYN"    ����ֻ���Լ������Լ� \n"NOR,
CYN"    ������������ǵ��� \n\n"NOR,
CYN"    ������������ǵ��� \n\n"NOR
});
    
string *everything = ({
    
HIB"  (Everything I Do) I Do It For You \n\n"NOR,

HIB"  Look into my eyes - you will see\n"NOR,
HIB"  What you mean to me\n"NOR,
HIB"  Search your heart - search your soul\n"NOR,
HIB"  And when you find me there you'll search no more\n"NOR,
HIB"  Don't tell me it's not worth tryin' for\n"NOR,
HIB"  You can't tell me it's not worth dyin' for\n"NOR,
HIB"  You know it's true\n"NOR,
HIB"  Everything I do - I do it for you\n"NOR,

HIB"  Look into my heart - you will find\n"NOR,
HIB"  There's nothin' there to hide\n"NOR,
HIB"  Take me as I am - take my life\n"NOR,
HIB"  I would give it all I would sacrifice\n"NOR,
HIB"  Don't tell me it's not worth fightin' for\n"NOR,
HIB"  I can't help it there's nothin' I want more\n"NOR,
HIB"  Ya know it's true\n"NOR,
HIB"  Everything I do - I do it for you\n"NOR,

HIB"  There's no love - like your love\n"NOR,
HIB"  And no other - could give more love\n"NOR,
HIB"  There's nowhere - unless you're there\n"NOR,
HIB"  All the time - all the way\n"NOR,

HIB"  Don't tell me it's not worth tryin' for\n"NOR,
HIB"  I can't help it there's nothin' I want more\n"NOR,
HIB"  I would fight for you - I'd lie for you\n"NOR,
HIB"  Walk the wire for you - Ya I'd die for you\n"NOR,

HIB"  Ya know it's true\n"NOR,
HIB"  Everything I do - I do it for you    \n"NOR
}); 
 
string *liuxing = ({
HIG"  ����֪�� �����ܷɶ�� ���������Ƿ�\n"NOR,
HIG"  ֵ��ȥѰ�� ҹ�յĻ� ɢ���������\n"NOR,
HIG"  �Ҹ����Һܾ� ֵ��ȥ�Ⱥ�\n\n"NOR,

HIG"  �������Ŀ� �ӻƻ赽�峿 �����ٳ���\n"NOR,
HIG"  ��Ը׹���������� �𻯳ɺ�ҹ�Ĳʺ� �ɱ���¹�����\n\n"NOR,

HIG"  ���¹����� �������� ������ĺ��� һֱ�ε���ͷ\n"NOR,
HIG"  ��������� �����Ը �����Ը���� ���ҵ�������\n\n"NOR,

HIG"  ��������ʱ�� ��Ը׹���������� �𻯳ɺ�ҹ�Ĳʺ�\n"NOR,
HIG"  ��Ը���ټ����ĵ��� ���ټ����ĵ��� �Ҹ�\n\n"NOR,

HIG"  ������ĺ��� һֱ�ε���ͷ ������ĺ� �����Ը����\n"NOR,
HIG"  ��������ʱ�� �����Ը ����֪�� �����ܷɶ��\n"NOR, 
HIG"  �Ҹ����Һܾ�\n\n\n\n"NOR
});
 
string *sadness = ({ 

 HIG"����ô������ѹ�\n\n"NOR, 


HIG"�����˼�� ��һ����һ��\n"NOR,
HIG"�µ����һ���û�иı�\n"NOR,
HIG"�������� ��ʱ���ܳ���\n"NOR,
HIG"�װ����� �����ټ���һ��\n\n"NOR,

HIG"����ķ� һ����Ĵ���\n"NOR,
HIG"������ȥ������ʱ��\n"NOR,
HIG"�����  ��������Щʲô\n"NOR,
HIG"Ϊʲô�������������ҳ���\n\n"NOR,

HIG"���������� ����ô������ѹ�\n"NOR,
HIG"��������Ҫ���ʱ�� û��˵һ�仰����\n"NOR,

HIG"���������� ����ô������ѹ�\n"NOR,
HIG"���㸶������ô�� ��ȴû�иж��� \n"NOR
});

string *weiyi = ({
    
HIG"������Ψһ\n\n"NOR,
 
HIG"��һЩ���� �ѵû�ӵ�� ������ʱ��\n"NOR,
HIG"���������� ����԰��� ���Ǹ�������\n"NOR,
HIG"�и��మ�� ����༮�� �����׻�ͷ\n"NOR,
HIG"ʲô���쳤 ʲô�еؾ� ����������\n\n"NOR,
 
HIG"ǧɽ���� �׺����� �δ����Ժ�\n"NOR,
HIG"�費��Ҫ��ŵ ���Ѳ�ĳ�ŵ ��ȡ��ȫ�ĸ���\n\n"NOR,
 
HIG"���п����� ˯���з��� ת����ȥ\n"NOR,
HIG"������Ư�� �紺ȥ���� ת����һ��\n"NOR,
HIG"��δ��Ϊ�� ���ڹµ��� ֻ�³��ܲ���\n"NOR,
HIG"�����ǹ�ȥ ȴ��֪���� ����Ҫ������\n\n"NOR,
 
HIG"�������·糾�����쳤�ؾ�\n"NOR,
HIG"�ջ��и����ѵ�ʱ��\n"NOR,
HIG"���ٺ�����¥�ѳɼ��ڲ���\n"NOR,
HIG"�ջ�ȵ�����������\n\n"NOR,
 
HIG"�ǹ��͵��� ����͵��� �ڱ�֯����\n"NOR,
HIG"ֻԸ����� ��Ը������ ���㲻����\n"NOR,
HIG"�������׺� ����Ҫɽ�� �������һ��\n"NOR,
HIG"��Ҫ˵��ȥ ��Ҫ�ʽ��� �˿��ս�����\n\n"NOR,
 
HIG"�����ǹ�ȥ �����Ž��� ������Ψһ\n"NOR });

string *yijianmei = ({
HIG"\n      һ �� ÷\n"NOR, 
HIG"            -- ������\n\n"NOR,

HIG"    ��ź�����̶��\n"NOR,
HIG"    ������� ��������\n"NOR,
HIG"    ����˭�Ľ�����\n"NOR,
HIG"    ���ֻ�ʱ ������¥ \n\n"NOR,

HIG"    ����Ʈ��ˮ����\n"NOR,
HIG"    һ����˼ �����г�\n"NOR,
HIG"    �����޼ƿ�����\n"NOR,
HIG"    ����üͷ,ȴ����ͷ\n"NOR});


string *unbreak = ({
HIC"\nUn-break my heart\n\n\n"NOR,
HIC"Don't leave me in all this pain \n"NOR,
HIC"Don't leave me out in the rain \n"NOR,
HIC"Come back and bring back my smile \n"NOR,
HIC"Come and take these tears away \n"NOR,
HIC"I need your arms to hold me now \n"NOR,
HIC"The nights are so unkind \n"NOR,
HIC"Bring back those nights when I held you beside me \n\n"NOR,

HIC"Un-break my heart \n"NOR,
HIC"Say you'll love me again \n"NOR,
HIC"Undo this hurt you caused \n"NOR,
HIC"When you walked out the door \n"NOR,
HIC"And walked outta my life \n"NOR,
HIC"Un-cry these tears \n"NOR,
HIC"I cried so many nights \n"NOR,
HIC"Un-break my heart \n"NOR,
HIC"My heart \n\n"NOR,

HIC"Take back that sad word good-bye \n"NOR,
HIC"Bring back the joy to my life \n"NOR,
HIC"Don't leave me here with these tears \n"NOR,
HIC"Come and kiss this pain away \n"NOR,
HIC"I can't forget the day you left \n"NOR,
HIC"Time is so unkind \n"NOR,
HIC"And life is so cruel without you here beside me \n\n"NOR,

HIC"Un-break my heart \n"NOR,
HIC"Say you'll love me again \n"NOR,
HIC"Undo this hurt you caused \n"NOR,
HIC"When you walked out the door \n"NOR,
HIC"And walked outta my life \n"NOR,
HIC"Un-cry these tears \n"NOR,
HIC"I cried so many nights \n"NOR,
HIC"Un-break my heart \n"NOR,
HIC"My heart \n"NOR,

HIC"Don't leave me in all this pain \n"NOR,
HIC"Don't leave me out in the rain \n"NOR,
HIC"Bring back the nights when I held you beside me \n"NOR,

HIC"Un-break my heart \n"NOR,
HIC"Say you'll love me again \n"NOR,
HIC"Undo this hurt you caused \n"NOR,
HIC"When you walked out the door \n"NOR,
HIC"And walked outta my life \n"NOR,
HIC"Un-cry these tears \n"NOR,
HIC"I cried so many, many nights \n"NOR,
HIC"Un-break my \n\n"NOR,

HIC"Un-break my heart \n"NOR,
HIC"Come back and say you love me \n"NOR,
HIC"Un-break my heart \n"NOR,
HIC"Sweet darlin' \n"NOR,
HIC"Without you I just can't go on \n"NOR,
HIC"Can't go on\n\n"NOR
});

string *imagine =
({ 
MAG"\nImagine\n\n\n"NOR,
MAG"Imagine there's no heaven,\n"NOR,
MAG"it's easy if you try,\n"NOR,
MAG"no hell below us,\n"NOR,
MAG"above us only sky,\n"NOR,
MAG"Imagine all the people,\n"NOR,
MAG"living for today.\n\n"NOR,

MAG"Imagine there's no country,\n"NOR,
MAG"it isn't hard to do,\n"NOR,
MAG"nothing to kill or die for,\n"NOR,
MAG"and no religion too,\n"NOR,
MAG"Imagine all the people,\n"NOR,
MAG"living life in peace.\n\n"NOR,

MAG"You may say I'm a dreamer,\n"NOR,
MAG"but I'm not the only one,\n"NOR,
MAG"I hope someday you'll join us,\n"NOR,
MAG"and the world will be as one.\n\n"NOR,

MAG"Imagine no possession,\n"NOR,
MAG"I wonder if you can,\n"NOR,
MAG"no need for greed or hunger,\n"NOR,
MAG"a brotherhood of man,\n"NOR,
MAG"Imagine all the people,\n"NOR,
MAG"sharing all the world.\n\n"NOR,

MAG"You may say I'm a dreamer,\n"NOR, 
MAG"but I'm not the only one,\n"NOR, 
MAG"I hope someday you'll join us,\n"NOR,
MAG"and the world will live as one\n"NOR 
}); 

void create()
{
    set( "short", MAG"����С��"NOR );
    set( "long", CYN"�����ģ�͸���ģ����β����ݶ��ϲ�����һ��һ����С�ƴ���\n" +
                    "����ǧ�ٿ�գ�۵�С������͵͵�ؿ����ŵ��ϵ����¡�ңԶ�ĵط�\n" +
                    "����ش�����һ�����(play)������\n"NOR );
    set( "cost", 0 );
    set("no_fight", "1"); 
    set("exits", ([ 
            "up" : __DIR__"loverroom1",
            "out" : __DIR__"path",
		])); 
    set("no_steal", 1); 
    set("no_sleep_room", 1); 
    setup();
}

void init()
{
    add_action( "play", "play" );
    add_action( "List", "list" );
    if ( this_player()->query( "id" ) == "mariner" )
        add_action( "stop", "stop" );
}

int stop( string arg )
{
    if ( playing )
    {
        remove_call_out( "PlaySong" );
        playing = 0;
    }    
    return 1;
}

int List( string arg )
{
    write( HIB"imagine -- Imagine by John Lennon.\n" );
    write( "unbreak -- Un-break my heart\n" );
    write( "yijianmei -- һ��÷*������\n" );
    write( "liuxing -- ���ǻ�԰\n" );
    write( "weiyi -- Ψһ\n" );
    write( "sadness -- ����ô������ѹ�\n" );
    write( "qfdy -- ��ǵ���\n" );
    write( "woman -- When you in love with a beautiful woman\n" );
    write( "zshyn -- ���ٻ�����\n" );
    write( "everything -- everything I do, I do it for you\n"NOR );
    return 1;
}

int play( string arg )
{
    if ( !arg ) 
        return notify_fail("��������ܶ࣬������������? ���ã�list��ѡ����Ҫ������Ŀ\n" );
    if ( playing ) 
        return notify_fail( "Music is playing.\n" );
    switch ( arg )
    {
    case "imagine":
        song = imagine;
        call_out( "PlaySong", 1, 0 );
        playing = 1;
        break;
    case "unbreak":
        song = unbreak;
        call_out( "PlaySong", 1, 0 );
        playing = 1;
        break;
    case "yijianmei":
        song = yijianmei;
        call_out( "PlaySong", 1, 0 );
        playing = 1;
        break;
    case "weiyi":
        song = weiyi;
        call_out( "PlaySong", 1, 0 );
        playing = 1;
        break;
    case "liuxing":
        song = liuxing;
        call_out( "PlaySong", 1, 0 );
        playing = 1;
        break;
    case "sadness":
        song = sadness; 
        call_out( "PlaySong", 1, 0 ); 
        playing = 1;
        break;
    case "everything":
        song = everything;
        call_out( "PlaySong", 1, 0 );
        playing = 1;
        break;
    case "qfdy": 
        song = qfdy;
        call_out( "PlaySong", 1, 0 );
        playing = 1;
        break;
    case "woman":
        song = woman;
        call_out( "PlaySong", 1, 0 );
        playing = 1;
        break;        
    case "zshyn":
        song = zshyn;
        call_out( "PlaySong", 1, 0 );
        playing = 1;
        break;        
    default:
        write( "We do not have this song.\n" );
        break;
    }
    return 1;
}

void PlaySong( int i )
{
    if ( i < sizeof ( song ) )
    {
        tell_room( this_object(), song[ i ] );
        i ++;
        remove_call_out( "PlaySong" );
        call_out( "PlaySong", 2, i );
    }
    else 
        playing = 0;    
}

