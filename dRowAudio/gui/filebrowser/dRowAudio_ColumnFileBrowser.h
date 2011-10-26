/*
 *  dRowAudio_ColumnFileBrowser.h
 *  dRowAudio
 *
 *  Created by David Rowland on 27/03/2009.
 *  Copyright 2009 dRowAudio. All rights reserved.
 *
 */

#ifndef __DROWAUDIO_COLUMNFILEBROWSER_H__
#define __DROWAUDIO_COLUMNFILEBROWSER_H__

#include "dRowAudio_BasicFileBrowser.h"

class ColumnFileBrowserContents;
class ColumnFileBrowserLookAndFeel;

//==================================================================================
/** A type of FileBrowser persented in columns.
 
    This is similar to OSX's Finder column view. You can navigate around the columns 
    using the keyboard or the mouse. Highligting a number of files and then dragging 
    them will perform an external drag and drop procedure.
 */
class ColumnFileBrowser :	public Viewport
{
public:
    //==================================================================================
    /** Creates a ColumnFileBrowser with a given file filter.
     */
	ColumnFileBrowser (WildcardFileFilter* filesToDisplay);
	
    /** Destructor.
     */
	~ColumnFileBrowser();
	
    /** @internal */
	void resized();
		
    /** @internal */
	void visibleAreaChanged (const Rectangle<int>& newVisibleArea);
	
    /** @internal */
	void mouseWheelMove (const MouseEvent& e, float wheelIncrementX, float wheelIncrementY);
	
private:
    //==================================================================================
	ScopedPointer<WildcardFileFilter> wildcard;
	ColumnFileBrowserContents* fileBrowser;
	
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ColumnFileBrowser);
};

#endif //__DROWAUDIO_COLUMNFILEBROWSER_H__